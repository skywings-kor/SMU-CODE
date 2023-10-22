import React, { useState, useEffect } from 'react';
import { View, FlatList, Image, Dimensions,Text,ScrollView, StyleSheet, TouchableOpacity,Modal, Button  } from 'react-native';
import {where, serverTimestamp,firestoreDB, firebaseAuth,collection, doc, setDoc, getDoc, query, orderBy, limit, getDocs, analytics, storage, ref, uploadBytes, getDownloadURL ,onAuthStateChanged, addDoc } from '../firebaseConfig';
import { useNavigation } from '@react-navigation/native';

import { Picker } from "@react-native-picker/picker";

const Home = () => {
  const [images, setImages] = useState([]);
  const [lastVisible, setLastVisible] = useState(null);
  const [loading, setLoading] = useState(false);

  //모달 true false
  const [modalVisible, setModalVisible] = useState(false);

    //지역선택설정
    const [selectedRegion, setSelectedRegion] = useState('대전광역시');
    const [selectedCity, setSelectedCity] = useState('동구');

    //지역
    const regions = [
      { name: '대전광역시', latitude: 36.3504, longitude: 127.3845 },
      { name: '서울특별시', latitude: 37.5665, longitude: 126.9780 },
      { name: '부산광역시', latitude: 35.1796, longitude: 129.0756 },
      { name: '광주광역시', latitude: 35.126033, longitude: 126.831302 },
      { name: '세종특별시', latitude: 36.56069, longitude: 127.2587334 },
      { name: '대구광역시', latitude: 35.798838, longitude: 128.583052 },
      { name: '인천광역시', latitude: 37.469221, longitude: 126.573234 },
      { name: '울산광역시', latitude: 35.519301, longitude: 129.239078 },
      { name: '경기도', latitude: 37.567167, longitude: 127.190292 },
      { name: '강원도', latitude: 37.555837, longitude: 128.209315 },
      { name: '충청남도', latitude: 36.557229, longitude: 126.779757 },
      { name: '충청북도', latitude: 36.628503, longitude: 127.929344 },
      { name: '경상북도', latitude: 36.248647, longitude: 128.664734 },
      { name: '경상남도', latitude: 35.259787, longitude: 128.664734 },
      { name: '전라북도', latitude: 35.716705, longitude:  127.144185 },
      { name: '전라남도', latitude: 34.819400, longitude: 126.893113 },
      { name: '제주특별자치도', latitude: 33.364805, longitude: 126.542671 }
    ];
  
    //도시
    const cities = [
      ['동구', '중구', '서구','유성구','대덕구'],
      ['서울시'],
      ['해운대구', '중구', '서구','동구','영도구','부산진구','동래구','남구','북구','사하구','금정구','강서구','연제구','수영구','사상구','기장군'],
      ['서구', '북구', '남구','동구','광산구'],
      ['세종시'],
      ['중구', '동구', '서구','남구','북구','수성구','달서구','달성군'],
      ['중구', '동구', '미추홀구','연수구','남동구','부평구','계양구','서구','강화군','옹진군'],
      ['중구','남구','동구','북구','울주군'],
      ['고양시', '수원시', '용인시','과천시','광명시','광주시','구리시','군포시','김포시','남양주시','동두천시','부천시','성남시','시흥시','안산시','안성시','안양시','양주시','여주시','오산시','의왕시','의정부시','이천시','파주시','평택시','포천시','하남시','화성시','가평군','양평군','연천군'],
      ['강릉시', '동해시', '삼척시','속초시','원주시','춘천시','태백시','고성군','양구군','양양군','영월군','인제군','정선군','철원군','평창군','홍천군','화천군','횡성군'],
      ['계룡시', '공주시', '논산시','당진시','보령시','서산시','아산시','천안시','금산군','부여군','서천군','예산군','청양군','태안군','홍성군'],
      ['제천시', '청주시', '충주시','괴산군','단양군','보은군','영동군','옥천군','음성군','증평군','진천군'],
      ['경산시', '경주시', '구미시','김천시','문경시','상주시','안동시','영주시','영천시','포항시'],
      ['창원시', '거제시', '김해시','밀양시','사천시','양산시','진주시','통영시'],
      ['군산시', '김제시', '남원시','익산시','전주시','정읍시', '장수군'],
      ['광양시', '나주시', '목포시','순천시','여수시'],
      ['서귀포시', '제주시']
    ];

    
  //상세페이지 이동
  const navigation = useNavigation();

  const handleItemClick = (item) => {
    navigation.navigate('Detail_Page', { itemData: item });
  }

  


  //Fucntion구간
  
  const handleRegionChange = (value) => {
    setSelectedRegion(value)
    setSelectedCity(cities[regions.findIndex((region) => region.name === value)][0])
  }

  const handleCityChange = (value) => {
    setSelectedCity(value)
  }

  const handleFilterButtonClick = () => {
    setModalVisible(true)
  }



  const loadImages = async () => {
    const db = firestoreDB;
    const boardCollectionRef = collection(db, "Board");
  
    let queryRef = query(boardCollectionRef, orderBy('number','desc'), limit(10));
    
   
    
    try {
      const imageDocs = await getDocs(queryRef); 
      const newImages = imageDocs.docs.map(doc => {
        return { id: doc.id, ...doc.data() };
      });
      
      setImages([]); // 상태 초기화
      if (newImages.length > 0) {
        setLastVisible(imageDocs.docs[imageDocs.docs.length - 1]);
        setImages(newImages); // 새로운 이미지로 상태 업데이트
      }
    } catch (error) {
      console.error('Error fetching documents:', error);
    }
  };
  
  const loadFilterImages = async () => {
    const db = firestoreDB;
    const boardCollectionRef = collection(db, "Board");

    let queryRef = query(boardCollectionRef, where("region", "==", selectedRegion), where("city", "==", selectedCity), orderBy('number', 'desc'), limit(10));
  
   
    
    try {
      const imageDocs = await getDocs(queryRef); 
      const newImages = imageDocs.docs.map(doc => {
        return { id: doc.id, ...doc.data() };
      });
      
      setImages([]); // 상태 초기화
      if (newImages.length > 0) {
        setLastVisible(imageDocs.docs[imageDocs.docs.length - 1]);
        setImages(newImages); // 새로운 이미지로 상태 업데이트
      }
    } catch (error) {
      console.error('Error fetching documents:', error);
    }
  };


  useEffect(() => {
    // console.log('Running useEffect');
    
    loadImages();

  }, []);
  

  
  

  return (
    <View style={styles.container}>
      <Button title={"최신화"} onPress={loadImages}/>
      <Modal
          animationType="slide"
          transparent={true}
          visible={modalVisible}
          onRequestClose={() => {
            setModalVisible(false)
          }}
        >
          
          <View style={styles.modalContainer}>
            <View style={styles.modalContent}>
              <Text style={styles.modalTitle}>기준 위치 설정</Text>
              <Text style={styles.label}>지역:</Text>
              <Picker
                selectedValue={selectedRegion}
                style={styles.picker}
                onValueChange={handleRegionChange}
              >
                {regions.map((region, index) => (
                  <Picker.Item key={index} label={region.name} value={region.name} />
                ))}
              </Picker>
              <Text style={styles.label}>도시:</Text>
              <Picker
                selectedValue={selectedCity}
                style={styles.picker}
                onValueChange={handleCityChange}
              >
                {cities[regions.findIndex((region) => region.name === selectedRegion)].map(
                  (city, index) => (
                    <Picker.Item key={index} label={city} value={city} />
                  )
                )}
              </Picker>
              
              <TouchableOpacity style={styles.applyButton} onPress={()=>{setModalVisible(false); loadFilterImages();}}>
                <Text style={styles.applyButtonText}>적용</Text>
              </TouchableOpacity>
            </View>
          </View>
          
        </Modal>


        
        <View style={styles.locationContainer}>
          <TouchableOpacity style={styles.button} onPress={handleFilterButtonClick}>
            <Text style={styles.buttonText}>필터</Text>
          </TouchableOpacity>
        </View>

      <FlatList
        data={images}
        numColumns={2}
        keyExtractor={item => item.id}
        onEndReachedThreshold={0.5}
        key={"two-columns"} // 추가된 부분
        renderItem={({ item }) => (
          <TouchableOpacity 
            style={styles.imageContainer} 
            onPress={() => handleItemClick(item)}
          >
            <Image source={{ uri: item.u_img }} style={styles.image} />
            <Text style={styles.dateLabel}>
              {item.timestamp?.toDate ? new Date(item.timestamp.toDate()).toISOString().split('T')[0] : 'Unknown Date'}
            </Text>
            <Text style={styles.regionLabel}>{item.region} {item.city}</Text>
          </TouchableOpacity>
        )}
      />
    </View>
  );

};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
  },
  imageContainer: {
    flex: 1,
    margin: 10,
    justifyContent: 'center',
    alignItems: 'center',
    borderColor: 'yellow',
    borderWidth: 2,
    borderRadius: 10,
  },
  image: {
    width: '90%',
    height: Dimensions.get('window').width * 0.6,
    borderRadius: 8,
    marginVertical: 10,
  },
  dateLabel: {
    marginTop: 5,
    fontSize: 16,
    fontWeight: 'bold',
  },
  regionLabel: {
    marginTop: 5,
    fontSize: 16,
  },
  filterButton: {
    position: 'absolute',
    top: '1%',
    alignSelf: 'center',
    backgroundColor: 'skyblue',
    borderRadius: 8,
    paddingVertical: 8,
    paddingHorizontal: 16,
  },
  filterButtonText: {
    color: 'white',
    fontWeight: 'bold',
  },
  scrollContainer:{
    backgroundColor: 'white',
  },
  modalContainer: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: 'rgba(0, 0, 0, 0.5)',
  },
  modalContent: {
    backgroundColor: 'white',
    padding: 16,
    borderRadius: 8,
  },
  modalTitle: {
    fontSize: 18,
    fontWeight: 'bold',
    marginBottom: 16,
  },
  label: {
    marginBottom: 8,
  },
  picker: {
    marginBottom: 16,
    height: 50,
    width: 200,
  },
  applyButton: {
    backgroundColor: 'skyblue',
    borderRadius: 8,
    paddingVertical: 8,
    paddingHorizontal: 16,
    alignSelf: 'flex-end',
  },
  applyButtonText: {
    color: 'white',
    fontWeight: 'bold',
  },
  button: {
    backgroundColor: 'skyblue',
    padding: 10,
    borderRadius: 5,
    marginTop: 10, // 버튼과 텍스트 사이에 마진 추가
    width: 50,
    height: 40,
    alignItems: 'center',
  },
  buttonText: {
    color: 'white',
    fontSize: 16,
    fontWeight: 'bold',
  },
  locationContainer: {
    alignItems: 'center',
    marginBottom: 0, // 원하는 만큼 마진 추가
  },

});

export default Home;
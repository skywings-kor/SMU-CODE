import React, { useState,useEffect  } from 'react';
import { StyleSheet,View, Text, Button, TextInput, Image, Modal, TouchableOpacity,ScrollView } from 'react-native';
import ImagePicker from 'react-native-image-picker';
import Geolocation from '@react-native-community/geolocation';
import { launchImageLibrary } from 'react-native-image-picker';
import { Picker } from "@react-native-picker/picker";

import MapView, { Marker } from 'react-native-maps';
import { serverTimestamp,firestoreDB, firebaseAuth,collection, doc, setDoc, getDoc, query, orderBy, limit, getDocs, analytics, storage, ref, uploadBytes, getDownloadURL ,onAuthStateChanged, addDoc } from '../firebaseConfig';


const AddPet=() => {

  //DB선언
  const db = firestoreDB;

  const [uid, setUid] = useState(null);

  //uid 넣기

  useEffect(() => {
    const unsubscribe = onAuthStateChanged(firebaseAuth, (user) => {
      if (user) {
        // 로그인한 사용자가 있으면 UID 설정
        setUid(user.uid);
      } else {
        // 로그인한 사용자가 없을 경우 로그나 경고 처리 등을 여기에서 수행할 수 있습니다.
        setUid(null);  // 선택사항: 로그아웃 시 uid 상태를 null로 설정
      }
    });

    // useEffect의 반환 함수를 사용하여 구독을 취소합니다.
    return () => unsubscribe();
  }, []);


  //이미지 URL
  const [imageURL,setimageURL] = useState("");

  //이미지
  const [image, setImage] = useState(null);
  
  // 1. selectedImages 상태를 추가합니다.
  const [selectedImages, setSelectedImages] = useState();

  //설명
  const [description, setDescription] = useState('');
  
  //위치
  const [location, setLocation] = useState({ latitude: 36.3504, longitude: 127.3845 });

  //모달 true false
  const [modalVisible, setModalVisible] = useState(false);
  
  //지역선택설정
  const [selectedRegion, setSelectedRegion] = useState('대전광역시');
  const [selectedCity, setSelectedCity] = useState('동구');

  //지도 표기(핑)
  const [userLatitude, setuserLatitude] = useState(0);
  const [markerPosition, setMarkerPosition] = useState(null);
  
  //지도 위도 관리
  const [mapRegion, setMapRegion] = useState({
    latitude: 36.3504,
    longitude: 127.3845,
    latitudeDelta: 0.6,
    longitudeDelta: 0.6,
  });


  //유저가 설정한 위치(초기값 서울임)
  const [userSelectedLong, setuserSelectedLong] = useState(0);
  const [userSelectedLat, setuserSelectedLat] = useState(9);
  


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



  //Function쪽
  
  //맵 핑 누를 경우 이벤트 발생

  const handleMapPress = (event) => {
    
    const { latitude, longitude } = event.nativeEvent.coordinate;
    setMarkerPosition({
      latitude: latitude,
      longitude: longitude
  });
  }






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


  //이미지 DB 업데이트
  const uploadImage = async (imageUser) => {
    try {
      const boardCollectionRef = collection(db, "Board");
      
      const queryRef = query(boardCollectionRef, orderBy('number'), limit(1));
      const querySnapshot = await getDocs(queryRef);
      const lastDoc = querySnapshot.docs[0];
      
      const lastNumber = lastDoc ? lastDoc.data().number : 0;
      const newNumber = lastNumber + 1;
      const folderName = newNumber.toString();
      
      
      // URI에서 Raw Byte 데이터 가져오기
    const response = await fetch(imageUser);

    const blob = await response.blob();
    
    const storageRef = ref(storage, `image/${folderName}/userimg`);
    
    await uploadBytes(storageRef, blob);
    
    const imageRef = ref(storage, `image/${folderName}/userimg`);
    const downloadURL = await getDownloadURL(imageRef);

    console.log (downloadURL);
    
    alert('이미지 업로드가 완료되었습니다.')
    return downloadURL;


    
  } catch (error) {
      console.error('이미지 업로드 중 오류 발생',error)
    }
  }




  //맵 필터(VIew 설정)
  const handleFilterApply = () => {
    setModalVisible(false)
    const selectedRegionData = regions.find((region) => region.name === selectedRegion)
    if (selectedRegionData) {
      setMapRegion({
        latitude: selectedRegionData.latitude,
        longitude: selectedRegionData.longitude,
        latitudeDelta: 0.6,
        longitudeDelta: 0.6,
      })
    }
  }

// 이미지 선택 함수
const chooseImage = () => {
  const options = {
    title: 'Choose Dog Image',
    storageOptions: {
      skipBackup: true,
      path: 'images',
    },
  };

  launchImageLibrary(options, (response) => {
    if (response.didCancel) {
      alert('User cancelled image picker');
    } else if (response.error) {
      alert('ImagePicker Error: ' + response.error);
    } else if (response.assets && response.assets.length > 0) {
      const chosenImage = response.assets[0].uri;

      // 선택된 이미지 URI 저장
      setSelectedImages(chosenImage);
    }
  });
};


  //맵 설정 사용자 핑 완료시
  const saveLostPetLocation=()=>{
    console.log(markerPosition.latitude)
  }



  //펫 작성 완료 버튼 눌렀을 때 발생하는거
  const submitProcess = async () => {

    try {
      let imageUploadURL = "";

      // 이미지 업로드 검증 & URL 가져오기
      if (selectedImages.length > 0) {
        imageUploadURL = await uploadImage(selectedImages); // 변경된 부분
      }
  
      const boardCollectionRef = collection(db, "Board");
      
      const queryRef = query(boardCollectionRef, orderBy('number', 'desc'), limit(1));
      const querySnapshot = await getDocs(queryRef);
      const lastDoc = querySnapshot.docs[0];
  
      // 마지막 번호 + 1
      const lastNum = lastDoc ? lastDoc.data().number : 0;
      const newNum = lastNum + 1;
      
      const userData = {
        number: newNum,
        region: selectedRegion,
        city: selectedCity,
        map_lat: markerPosition.latitude,
        map_long: markerPosition.longitude,
        u_explain: description,
        comment: [],
        u_img: imageUploadURL,
        user_uid: uid,
        timestamp: serverTimestamp(),
      };
      
      const docRef = doc(boardCollectionRef, newNum.toString());
      
      // Firestore에 새 문서로 데이터 추가하기
      await setDoc(docRef, userData);
  
      alert("성공적으로 업로드가 완료되었습니다.");
    } catch (error) {
      console.error("오류 발생:", error);
      alert('오류 발생');
    }
  };
  


  return (
  <ScrollView>

<View style={{ flex: 1, padding: 16,alignItems: 'center',justifyContent: 'center', }}>
  {selectedImages && <Image source={{ uri: selectedImages }} style={{ width: 200, height: 200, marginTop: 16,alignItems: 'center', }} />}
  <Button title="이미지를 선택해주세요" onPress={chooseImage} /> 
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
              
              <TouchableOpacity style={styles.applyButton} onPress={handleFilterApply}>
                <Text style={styles.applyButtonText}>적용</Text>
              </TouchableOpacity>
            </View>
          </View>
          
        </Modal>
        
        <View style={styles.locationContainer}>
          <Text style={styles.locationText}>지역: <Text style={styles.locationValue}>{selectedRegion} {selectedCity}</Text></Text>
          <TouchableOpacity style={styles.button} onPress={handleFilterButtonClick}>
            <Text style={styles.buttonText}>위치 설정</Text>
          </TouchableOpacity>
        </View>



        <View style={{ flex: 1}}>

        <MapView
          style={{ flex: 1 }}
          region={mapRegion}
          onPress={handleMapPress}
          style={{ flex: 1 ,width:300,height:300}}
        >
    {markerPosition && <Marker coordinate={markerPosition} />}
</MapView>

          {/* <Button title="위치 저장" onPress={saveLostPetLocation} />  */}
        </View>

        <TextInput
          placeholder="설명을 적어주세요"
          value={description}
          onChangeText={setDescription}
          style={{ borderWidth: 1, marginTop: 16, padding: 8, width:300, height:200 }}
          multiline
        />
                  

        <View style={{width:200}}>
        <Button title="등록" onPress={() => {submitProcess()}}  />
        </View>
      </View>
                
    </ScrollView>
  )
}

export default AddPet;



const styles = StyleSheet.create({
  ImageSize:{
    margin:'5%',
    width:"90%",
    height:150,
  },
  PlaceContainer:{
    borderColor:"gray",
    borderWidth:2,
    margin:10,
  },
  name: {
    fontSize: 16,
    fontWeight: 'bold',
    marginBottom: 5,
    marginLeft:"5%",
  },
  location: {
    fontSize: 14,
    height: 20,
    marginLeft:"5%",
    width: '80%',
    marginBottom: 5,
  },
  infoContainer: {
    flex: 1,
    marginRight: 10,
  },
  onrow:{
    flexDirection:'row',
    alignItems:'flex-start',
  },
  like: {
    marginLeft: 5,
    marginRight: 5,
},
imagelike:{
    width: 20,
    height: 20,
    resizeMode: 'cover',
    marginLeft:"5%",
    marginBottom:"5%",
    borderRadius: 8,
},
  container: {
    flex: 1,
  },
  map: {
    width: '100%',
    height: '100%',
  },
  ListButton:{
    position: 'absolute',
    bottom: '1%',
    alignSelf: 'center',
    backgroundColor: 'skyblue',
    borderRadius: 8,
    paddingVertical: 8,
    paddingHorizontal: 16,
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
  locationContainer: {
    alignItems: 'center',
    marginBottom: 20, // 원하는 만큼 마진 추가
  },
  locationText: {
    fontSize: 18,
    fontWeight: 'bold',
    marginTop:30,
  },
  locationValue: {
    color: 'blue', // 원하는 색상으로 변경
  },
  button: {
    backgroundColor: 'skyblue',
    padding: 10,
    borderRadius: 5,
    marginTop: 10, // 버튼과 텍스트 사이에 마진 추가
    width: 200,
    height: 40,
    alignItems: 'center',
  },
  buttonText: {
    color: 'white',
    fontSize: 16,
    fontWeight: 'bold',
  },
});
 
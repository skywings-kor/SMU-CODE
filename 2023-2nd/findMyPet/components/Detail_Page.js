import React, { useState, useEffect } from 'react';
import {
  View,
  FlatList,
  Image,
  Dimensions,
  Text,
  TextInput,
  Button,
  StyleSheet,
  ScrollView
} from 'react-native'

import {updateDoc,arrayUnion, serverTimestamp,firestoreDB, firebaseAuth,collection, doc, setDoc, getDoc, query, orderBy, limit, getDocs, analytics, storage, ref, uploadBytes, getDownloadURL ,onAuthStateChanged, addDoc } from '../firebaseConfig';
import MapView, { Marker } from 'react-native-maps';

const Detail_Page = (props) => {
  //값 받아온거
  const { route } = props;
  const { itemData } = route.params;

  const [images, setImages] = useState([]);
  
  const [markerPosition, setMarkerPosition] = useState({
    latitude: itemData.map_lat,
    longitude: itemData.map_long
  });

  //지도 위도 관리
  const [mapRegion, setMapRegion] = useState({
    latitude: itemData.map_lat,
    longitude: itemData.map_long,
    latitudeDelta: 0.009,
    longitudeDelta: 0.009,
  });



  // 댓글 관련 상태
  const [comment, setComment] = useState('');
  const [comments, setComments] = useState([]);


  const handleAddComment = async () => {
    if (comment.trim() !== '') {
      // 댓글 추가 전에 최신 댓글 데이터를 불러옵니다.
      await fetchComments();

      // 이후에 기존의 댓글들에 새로운 댓글을 추가합니다.
      const updatedComments = [...comments, comment];

      // Board의 문서에 접근합니다.
      const boardDocRef = doc(firestoreDB, 'Board', itemData.id);

      // comment 필드를 업데이트합니다.
      await updateDoc(boardDocRef, {
        comment: updatedComments
      });

      setComment('');

      // 댓글을 추가한 후에는 다시 최신 댓글 데이터를 불러옵니다.
      fetchComments();
    }
  };


  const fetchComments = async () => {
    try {
        const boardDocRef = doc(firestoreDB, "Board", itemData.id); // "3"을 해당 문서의 ID로 변경하세요.
        const boardDocSnap = await getDoc(boardDocRef);

        if (boardDocSnap.exists()) {
            const load_Comment = boardDocSnap.data().comment;
            setComments(load_Comment)
            console.log(load_Comment); // 배열 형태의 댓글을 콘솔에 출력
        } else {
            console.log("No such document!");
        }
    } catch (error) {
        console.error("Error fetching comments:", error);
    }
}


  useEffect(() => {
    fetchComments();
    console.log(itemData)
  }, []);

  //시간
  const dateTimeString = itemData.timestamp?.toDate 
  ? new Date(itemData.timestamp.toDate()).toISOString().slice(0, 19).replace('T', ' ')
  : 'Unknown Date and Time';

  const db = firestoreDB;


  return (
    <ScrollView style={styles.container}>
      <View style={{ flex: 1, padding: 16,alignItems: 'center',justifyContent: 'center', }}>
        <Text style={styles.namestyle}>발견 위치</Text>
        <MapView
          style={{ flex: 1 }}
          region={mapRegion}
          style={{ flex: 1, width: 300, height: 300 }}
        >
          {markerPosition && <Marker coordinate={markerPosition} />}
        </MapView>

        <Text style={styles.namestyle}>발견 사진</Text>
        <Image source={{ uri: itemData.u_img }} style={styles.image} />

        <Text style={styles.namestyle}>발견 설명</Text>
        <Text style={styles.dateLabel}>
        {itemData.u_explain}
        </Text>

        <Text style={styles.namestyle}>등록 일자(시간)</Text>
        <Text style={styles.dateLabel}>
        {dateTimeString}
        </Text>


        <Text style={styles.namestyle}>댓글 리스트</Text>
        {/* 댓글 목록 */}
      {comments.map((comment, index) => (
    <Text key={index} style={styles.emplike}>{comment}</Text>
      ))}

        {/* 댓글 입력 창 */}
      <View style={styles.commentInputContainer}>
        <TextInput
          style={styles.commentInput}
          value={comment}
          onChangeText={setComment}
          placeholder="댓글을 입력하세요..."
        />
        <Button title="댓글 달기" onPress={handleAddComment} />
      </View>
      

      </View>
    </ScrollView>
  );
};

export default Detail_Page;

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
    height: Dimensions.get('window').width * 0.9,
    borderRadius: 8,
    marginVertical: 10,
  },
  dateLabel: {
    marginTop: 5,
    fontSize: 22,
    fontWeight: 'bold',
  },
  regionLabel: {
    marginTop: 5,
    fontSize: 22,
  },
  namestyle:{
    marginTop: 20,
    fontSize: 25,
    textAlign: 'left',
    color: 'skyblue',
    textDecorationLine: 'underline',
  },
  emplike:{
    fontSize: 20,
    color: 'black',
    fontWeight:'bold'
},
});

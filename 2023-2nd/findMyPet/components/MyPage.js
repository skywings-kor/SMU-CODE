import React, { useEffect, useState } from 'react';
import {Button, FlatList,ScrollView, View, Image, Text, StyleSheet, SafeAreaView, TouchableOpacity,ActivityIndicator } from 'react-native';
import {where, serverTimestamp,firestoreDB, firebaseAuth,collection, doc, setDoc, getDoc, query, orderBy, limit, getDocs, analytics, storage, ref, uploadBytes, getDownloadURL ,onAuthStateChanged, addDoc } from '../firebaseConfig';
import { useNavigation } from '@react-navigation/native';

const MyPage = () => {
  const [userPosts, setUserPosts] = useState([]); // 사용자의 게시글을 저장할 state
  
  const fetchUserPosts = async () => {
    const currentUser = firebaseAuth.currentUser; // 현재 로그인한 사용자 가져오기
    console.log("hi")
    console.log(currentUser.uid)
    if (currentUser) {
      const db = firestoreDB;
      const postsRef = collection(db, "Board"); // 게시글을 저장하는 컬렉션 이름
      const userPostsQuery = query(postsRef, where("user_uid", "==", currentUser.uid));

      try {
        const postDocs = await getDocs(userPostsQuery);
        const userPostsData = postDocs.docs.map(doc => ({ id: doc.id, ...doc.data() }));
        setUserPosts(userPostsData);
      } catch (error) {
        console.error("Error fetching user's posts:", error);
      }
    }
  };


  useEffect(() => {
    
    fetchUserPosts();
  }, []);

  //상세페이지 이동
  const navigation = useNavigation();

  const handleItemClick = (item) => {
    navigation.navigate('Detail_Page', { itemData: item });
  }

  
  const renderItem = ({ item }) => (
    <TouchableOpacity style={styles.postContainer} onPress={() => handleItemClick(item)}>
      <Image source={{ uri: item.u_img }} style={styles.postImage} />
      <View style={styles.postDetails}>
        <Text style={styles.postDate}>
          {item.timestamp?.toDate ? new Date(item.timestamp.toDate()).toISOString().split('T')[0] : 'Unknown Date'}
        </Text>
        <Text style={styles.postLocation}>{item.region} {item.city}</Text>
      </View>
    </TouchableOpacity>
  );

  return (
    <View style={styles.container}>
        <Text style={styles.greetingText}> 작성한 글입니다. </Text>
        <Button title={"최신화"} onPress={()=> fetchUserPosts()}/>
        <FlatList
          data={userPosts}
          renderItem={renderItem}
          keyExtractor={item => item.id}

          
        />
    </View>
  )
};

export default MyPage;

const styles = StyleSheet.create({
  container: {
    flex: 1,
    padding: 15,
    backgroundColor: '#f7f7f7'
  },
  greetingText: {
    fontSize: 20,
    fontWeight: 'bold',
    marginBottom: 20,
    color: '#333',
    alignSelf: 'center'
  },
  postContainer: {
    flexDirection: 'row',
    marginBottom: 15,
    borderRadius: 10,
    backgroundColor: '#ffffff',
    shadowColor: '#000',
    shadowOffset: {
      width: 0,
      height: 2
    },
    shadowOpacity: 0.23,
    shadowRadius: 2.62,
    elevation: 4
  },
  postImage: {
    width: 100,
    height: 100,
    borderRadius: 10
  },
  postDetails: {
    flex: 1,
    padding: 10
  },
  postDate: {
    color: '#888',
    fontSize: 12
  },
  postLocation: {
    color: '#333',
    fontSize: 16,
    marginTop: 5
  }
});
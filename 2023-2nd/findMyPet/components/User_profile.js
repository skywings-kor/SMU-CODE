import React, { useEffect, useState } from 'react';
import { ScrollView, View, Image, Text, StyleSheet, SafeAreaView, TouchableOpacity,ActivityIndicator } from 'react-native';


import { signOut, firebaseAuth } from '../firebaseConfig';


const User_profile = () => {
  const auth = firebaseAuth;


  const handleLogout = () => {
    // 로그아웃 처리 로직
    // 로그아웃 성공 시 setIsLoggedIn(false) 호출
    signOut(firebaseAuth)
      .then(() => {
        setIsLoggedIn(false);
        console.log('로그아웃 성공');
      })
      .catch((error) => {
        console.log('로그아웃 실패:', error);
      });
  };

  return (
    <View>
        <Text> 안녕하세요! </Text>
    </View>

  )
};


export default User_profile;
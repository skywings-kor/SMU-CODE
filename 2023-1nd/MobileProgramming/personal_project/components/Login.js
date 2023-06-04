import React, { useState } from 'react';
import { StyleSheet, Text, View, TextInput, Button } from 'react-native';
import {firebaseAuth,signInWithEmailAndPassword} from '../firebaseConfig'

export default function Login({ handleLogin, navigation }) {
    const handleSignup = () => {
        navigation.navigate('SignUp');
      };

    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');
  
    const auth = firebaseAuth;
  
    const handleLoginPress = () => {
      signInWithEmailAndPassword(auth, email, password)
        .then((userCredential) => {
          // 로그인 성공 처리
          console.log('로그인 성공:', userCredential.user);
          handleLogin();
        })
        .catch((error) => {
          // 로그인 실패 시 처리할 코드입니다!
          if (error.code === 'auth/invalid-email') {
            alert('아이디 혹은 비밀번호가 틀렸습니다.');
          }
        });
    };
  
    return (
      <View style={styles.container}>
        <TextInput
          style={styles.input}
          placeholder="Email"
          onChangeText={(text) => setEmail(text)}
        />
        <TextInput
          style={styles.input}
          placeholder="Password"
          secureTextEntry={true}
          onChangeText={(text) => setPassword(text)}
        />
        <Button onPress={handleLoginPress} title="로그인" style={styles.button}/>
        <Button onPress={handleSignup} title="회원가입" color="blue" style={styles.button}/>

      </View>
    );
  }

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    padding: 16,
  },
  input: {
    marginBottom: 10,
    paddingHorizontal: 8,
    paddingVertical: 6,
    borderBottomWidth: 1,
    borderBottomColor: '#ddd',
  },
  button: {
    width: 200,
    height: 50,
    marginVertical: 10,
  },
  
});
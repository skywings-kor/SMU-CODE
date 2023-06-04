import React, { useState } from 'react';
import { View, Text, TextInput, Button, StyleSheet } from 'react-native';
import { firestoreDB,createUserWithEmailAndPassword,firebaseAuth , addDoc,doc,setDoc,getDoc} from '../firebaseConfig';

import { useNavigation } from '@react-navigation/native';

const Signup = () => {
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const navigation = useNavigation();

  const auth = firebaseAuth;
  const db = firestoreDB
    

  const handleSignup = () => {
    createUserWithEmailAndPassword(auth, email, password)
      .then((userCredential) => {
        const uid = userCredential.user.uid;
        const userDocRef = doc(db, `MobileAssignment/${uid}`)
        const userData = {
            time: '',
            task: '',
        }

        //파이어스토어한테 이제 보냅니다
        setDoc(userDocRef, userData)
          .then(() => {

          })

          .catch((error) => {
            alert('firestore 문서 생성에 실패했습니다:');
          });

          
        alert('회원가입 성공!');
        // 여기에 회원가입 후 처리할 로직 추가
      })
      .catch((error) => {
        const errorCode = error.code;
        const errorMessage = error.message;
    
        if (errorCode === 'auth/weak-password') {
          alert('비밀번호는 최소 6자 이상이어야 합니다.');
        } else if (errorCode === 'auth/email-already-in-use') {
          alert('이미 사용 중인 이메일입니다.');
        } else if (errorCode === 'auth/invalid-email') {
          alert('유효하지 않은 이메일입니다.');
        } else {
          alert(errorMessage);
        }
      });
  };

  return (
    <View style={styles.container}>
      <TextInput
        placeholder="Email"
        onChangeText={(text) => setEmail(text)}
        value={email}
        style={styles.input}
      />
      <TextInput
        placeholder="Password"
        onChangeText={(text) => setPassword(text)}
        value={password}
        secureTextEntry
        style={styles.input}
      />
      <Button onPress={handleSignup} title="회원가입 진행" color="coral" />
    </View>
  );
}
export default Signup;


const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
  title: {
    fontSize: 24,
    marginBottom: 20,
  },
  input: {
    width: '80%',
    height: 40,
    marginBottom: 10,
    borderWidth: 1,
    borderColor: '#ccc',
    paddingHorizontal: 10,
  },
});
import React, { useState } from 'react';
import { StyleSheet, Text, View, TextInput, Button } from 'react-native';
import { firestoreDB, getFirestore,serverTimestamp,setDoc,getDoc,addDoc,doc,firebaseAuth,collection } from '../firebaseConfig';
import { format } from 'date-fns';

const db = firestoreDB;

export default function AddTodo({ submitHandler }) {
  const [text, setText] = useState('');
  const [year, setYear] = useState('');
  const [month, setMonth] = useState('');
  const [day, setDay] = useState('');

  //현재 로그인한 사용자의 uid 정보값을 가져오기
  const user = firebaseAuth.currentUser;
  const uid = user.uid;


  const changeHandler = (val) => {
    setText(val);
  };
  const addTodo = () => {
    const selectedDate = new Date(year, month - 1, day);
    const timestamp = serverTimestamp();
    //파이어 스토어 서버 시간 가져오기
    const selectedDateStr = selectedDate ? format(selectedDate, 'yyyy-MM-dd') : null;

    const userDocRef = doc(db, `MobileAssignment/${uid}`);
    const dateDocRef = collection(userDocRef, 'dates');
    const newTodoDocRef = doc(dateDocRef, selectedDateStr);

    const newTodoData = {
        task: text,
        writeTime: timestamp,
    };

    setDoc(newTodoDocRef, newTodoData)
        .then(() => {
            alert('성공적으로 입력되었습니다');
        })
        .catch((error) => {
            alert('입력에 실패하였습니다');
        });
  };

  return (
    <View>
      <View style={styles.dateContainer}>
        
        <View style={styles.inputContainer}>
          <TextInput
            style={styles.input}
            placeholder="Year"
            onChangeText={(val) => setYear(val)}
            value={year}
            keyboardType="numeric"
          />
          <TextInput
            style={styles.input}
            placeholder="Month"
            onChangeText={(val) => setMonth(val)}
            value={month}
            keyboardType="numeric"
          />
          <TextInput
            style={styles.input}
            placeholder="Day"
            onChangeText={(val) => setDay(val)}
            value={day}
            keyboardType="numeric"
          />
        </View>
        <View style={styles.inputContainer}>

          <TextInput
            style={styles.input}
            placeholder="new todo..."
            onChangeText={changeHandler}
            value={text}
          />
        </View>
        
      </View>
      <Button onPress={addTodo} title="일정 추가" color="coral" style={styles.button} />
    </View>
  );
}

const styles = StyleSheet.create({
  dateContainer: {
    position: 'relative',
    marginBottom: 10,
  },
  inputContainer: {
    flexDirection: 'row',
    justifyContent: 'space-between',
    marginBottom: 10,
  },
  textInputContainer: {
    marginTop: 40,
    marginLeft: 2,
  },
  input: {
    flex: 1,
    marginBottom: 10,
    paddingHorizontal: 8,
    paddingVertical: 6,
    borderBottomWidth: 1,
    backgroundColor: 'white', // 텍스트 입력 칸의 배경색을 흰색으로 설정합니다.
    color: 'black', // 텍스트 색상을 검은색으로 설정합니다.
  },
  button: {
    marginTop: 20,
    marginBottom: 10,
  },
});
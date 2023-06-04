import React, { useState, useEffect } from 'react';
import { StyleSheet, Text, View, FlatList,TouchableOpacity } from 'react-native';
import Header from './Header';
import TodoItem from './Body';
import AddTodo from './addTodo';
import { firebaseAuth, firestoreDB, doc, collection, getDocs,onSnapshot,deleteDoc  } from '../firebaseConfig';

export default function Home() {
  const user = firebaseAuth.currentUser;
  const uid = user.uid;
  const db=firestoreDB
  const [upcomingTodos, setUpcomingTodos] = useState([]);

  
  const submitHandler = async (text) => {
    try {
      const userDocRef = doc(db, `MobileAssignment/${uid}`);
      const dateDocRef = collection(userDocRef, 'dates');
      const newTodoDocRef = doc(dateDocRef, text);
      const newTodoData = {
        task: text,
        writeTime: new Date().toISOString(),
      };
  
      await setDoc(newTodoDocRef, newTodoData);
      getUpcomingTodos(); // 일정 추가 후에 getUpcomingTodos 호출
    } catch (error) {
      console.log('Error adding upcoming todo:', error);
    }
  };
  const getUpcomingTodos = async () => {
    try {
      const userDocRef = doc(db, `MobileAssignment/${uid}`);
      const dateDocRef = collection(userDocRef, 'dates');
  
      onSnapshot(dateDocRef, (snapshot) => {
        const todos = [];
        snapshot.forEach((doc) => {
          const todo = { id: doc.id, ...doc.data() };
          todos.push(todo);
        });
        setUpcomingTodos(todos);
      });
    } catch (error) {
      console.log('Error getting upcoming todos:', error);
    }
  };

  const deleteTodo = async (id) => {
    try {
      const userDocRef = doc(db, `MobileAssignment/${uid}`);
      const dateDocRef = collection(userDocRef, 'dates');
      const todoDocRef = doc(dateDocRef, id);

      await deleteDoc(todoDocRef);
      await getUpcomingTodos();
    } catch (error) {
      console.log('Error deleting todo:', error);
    }
  };

  useEffect(() => {
    getUpcomingTodos();
  }, [uid]);


  // 다른 코드 생략

  return (
    <View style={styles.container}>
      <Header />
      <View style={styles.content}>
        <AddTodo submitHandler={submitHandler} />
        <View style={styles.list}>
        {upcomingTodos.map((todo) => (
            <TouchableOpacity key={todo.id} onPress={() => deleteTodo(todo.id)}>
            <Text style={styles.upcomingItem}>{todo.id} - {todo.task}</Text>
            </TouchableOpacity>
        ))}
        </View>
      </View>
    </View>
  );
}

// 다른 코드 생략

const styles = StyleSheet.create({
    container: {
      flex: 1,
      justifyContent: 'center',
      alignItems: 'center',
      backgroundColor: '#fff',
    },
    content: {
      width: '90%',
      padding: 40,
    },
    list: {
      marginTop: 20,
    },
    upcomingItem: {
      marginBottom: 10,
    },
  });
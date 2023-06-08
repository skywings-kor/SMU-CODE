import React, { useState, useEffect } from 'react';
import { StyleSheet, View, Text } from 'react-native';
import { Calendar } from 'react-native-calendars';
import { firebaseAuth, firestoreDB, doc, collection, query, where, getDocs } from '../firebaseConfig';

export default function CalendarScreen() {
  const user = firebaseAuth.currentUser;
  const uid = user.uid;
  const db = firestoreDB;
  const [todos, setTodos] = useState([]);
  const [selectedDate, setSelectedDate] = useState('');
  const [markedDates, setMarkedDates] = useState({});

  useEffect(() => {
    loadTodos();
  }, []);

  const loadTodos = async () => {
    try {
      const userDocRef = doc(db, `MobileAssignment/${uid}`);
      const datesCollectionRef = collection(userDocRef, 'dates');
      const querySnapshot = await getDocs(datesCollectionRef);
  
      const todosData = [];
      let markedDatesData = {}; // 변경된 부분
      querySnapshot.forEach((doc) => {
        const date = doc.id;
        const task = doc.data().task || '';
        todosData.push({ date, task });
        markedDatesData[date] = { marked: true, dotColor: 'blue' };
      });
  
      setTodos(todosData);
      setMarkedDates({ ...markedDatesData }); // 변경된 부분
    } catch (error) {
      console.log('Error loading todos:', error);
    }
  };

  const handleDateSelect = (date) => {
    setSelectedDate(date.dateString);
  };

  const filteredTodos = todos.filter((todo) => {
    return todo.date === selectedDate;
  });

  return (
    <View style={styles.container}>
      <Calendar
        onDayPress={handleDateSelect}
        markedDates={markedDates} // 변경된 부분
      />
      {selectedDate ? (
        <View>
        <Text style={styles.header}>해당 일자의 해야 할 일 입니다!</Text>
        {/* Display filtered todos for selected date */}
        {filteredTodos.map((todo, index) => (
          <Text key={index} style={styles.todoText}>{todo.task}</Text>
        ))}
      </View>
      ) : null}
    </View>
  );
}

const styles = StyleSheet.create({
    container: {
      flex: 1,
      backgroundColor: '#fff',
    },
    header: {
      textAlign: 'center',
      fontSize: 18,
      fontWeight: 'bold',
      marginTop: 10,
      marginBottom: 10,
      color:'blue'
    },
    todoText: {
      textAlign: 'center',
      fontSize: 25,
      marginBottom: 5,
    },
  });
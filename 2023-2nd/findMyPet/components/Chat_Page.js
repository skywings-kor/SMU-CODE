
import React, { useState } from 'react';
import { View, Text, TextInput, Button, FlatList, StyleSheet } from 'react-native';

const Chat_Page = () => {
  const [message, setMessage] = useState('');
  const [chat, setChat] = useState([]);

  const handleSubmit = async () => {
    if (message.trim().length === 0) return;

    // 사용자 메시지 추가
    const userMessage = {
      id: Date.now(),
      text: message,
      sender: 'user'
    };
    setChat(prevChat => [...prevChat, userMessage]);

    // Flask 서버에 메시지 전송 및 응답 처리
    try {
        
      
      let response = await fetch('http://10.0.2.2:5000/chatbot_serv', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json'
        },
        body: JSON.stringify({ message })
      });
      let responseData = await response.json();

    // console.log("tetete")

      const serverMessage = {
        id: Date.now() + 1,
        text: responseData.reply,
        sender: 'server'
      };
      setChat(prevChat => [...prevChat, serverMessage]);
    } catch (error) {
      console.error('Error:', error);
    }

    setMessage('');
  };

  const renderItem = ({ item }) => {
    const isUserMessage = item.sender === 'user';
    return (
      <View style={[styles.message, isUserMessage ? styles.userMessage : styles.serverMessage]}>
        <Text>{item.text}</Text>
      </View>
    );
  };

  return (
    <View style={styles.container}>
      <FlatList
        data={chat}
        renderItem={renderItem}
        keyExtractor={item => item.id.toString()}
        style={styles.chatList}
      />
      <View style={styles.inputContainer}>
        <TextInput
          value={message}
          onChangeText={setMessage}
          style={styles.input}
          placeholder="메시지를 입력하세요"
        />

        <Button title="전송" onPress={handleSubmit} />
      </View>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    padding: 15,
    backgroundColor: '#f5f5f5'
  },
  chatList: {
    flex: 1
  },
  message: {
    padding: 10,
    borderRadius: 10,
    marginBottom: 10
  },
  userMessage: {
    alignSelf: 'flex-end',
    backgroundColor: '#e1ffdb',
    marginRight: 10
  },
  serverMessage: {
    alignSelf: 'flex-start',
    backgroundColor: '#dbf5ff',
    marginLeft: 10
  },
  inputContainer: {
    flexDirection: 'row',
    alignItems: 'center',
    borderTopWidth: 1,
    borderTopColor: '#e1e1e1',
    padding: 10
  },
  input: {
    flex: 1,
    padding: 10,
    borderRadius: 10,
    backgroundColor: '#ffffff',
    marginRight: 10
  }
});

export default Chat_Page;
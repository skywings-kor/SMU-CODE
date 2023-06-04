import { StatusBar } from 'expo-status-bar';
import React, {useState} from 'react';
import { StyleSheet, Text, View, FlatList,  } from 'react-native';

import Home from './components/Home'
import Login from './components/Login'
import SignUp from './components/Signup';
import Calendar from './components/Calendar';

import { NavigationContainer } from '@react-navigation/native';
import { createStackNavigator } from '@react-navigation/stack';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';

const Stack = createStackNavigator();
const Tab = createBottomTabNavigator();

export default function App() {
  const [isLoggedIn, setIsLoggedIn] = useState(false);

  const handleLogin = () => {
    // 로그인 처리 로직
    // 로그인 성공 시 setIsLoggedIn(true) 호출
    setIsLoggedIn(true);
  };
  
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
    <NavigationContainer>
          <Stack.Navigator
        screenOptions={{
          headerShown: false, // Main 스크린의 헤더 숨김
        }}
      >
        {isLoggedIn ? (
          <Stack.Screen name="Main">
            {() => (
              <Tab.Navigator
                screenOptions={({ route }) => ({
                  headerShown: true, // 탭 내비게이터의 헤더 표시
                  headerTitle: route.name, // 탭 이름으로 헤더 타이틀 설정
                  headerTitleAlign: 'center', // 헤더 타이틀 가운데 정렬
                })}
              >
                <Tab.Screen name="Home" component={Home} />
                <Tab.Screen name="Calendar" component={Calendar} />
              </Tab.Navigator>
            )}
          </Stack.Screen>
        ) : (
          <>
            <Stack.Screen name="Login">
              {(props) => <Login {...props} handleLogin={handleLogin} />}
            </Stack.Screen>
            <Stack.Screen name="SignUp" component={SignUp} />
          </>
        )}
      </Stack.Navigator>
  </NavigationContainer>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
  },
});
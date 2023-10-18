import React, {useState} from 'react';
import { StyleSheet, View, Text, TouchableOpacity } from 'react-native';

import SignUp from "./components/SignUp"
import Login from "./components/Login"
import HM from "./components/Home"
import UI from "./components/User_profile"

import { createStackNavigator } from "@react-navigation/stack";
import { createBottomTabNavigator } from "@react-navigation/bottom-tabs";
import { NavigationContainer } from "@react-navigation/native";

const Stack = createStackNavigator()
const Tab = createBottomTabNavigator();


const App =()=>{
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
      {isLoggedIn ? (
        <Tab.Navigator
          initialRouteName="mainTab"
          screenOptions={{
            activeBackgroundColor: 'white',
            tabBarActiveTintColor: 'rgb(182,20,45)',
            style: {
              borderTopWidth: 0, // 상단 경계선 제거
            },
            headerShown: false,
          }}
        >
          <Tab.Screen
            name="Main"
            component={MainScreen}
          />

          <Tab.Screen
            name="MyPage"
            component={UI}
          />

          <Tab.Screen
            name="PET등록"
            component={UI}
          />

        </Tab.Navigator>
      ) : (
        <Stack.Navigator>
          <Stack.Screen
            name="Login"
            component={(props) => <Login {...props} handleLogin={handleLogin} />}
            options={{ headerShown: false }}
          />
          <Stack.Screen
            name="SignUp"
            component={SignUp}
            options={{ headerShown: false }}
          />
        </Stack.Navigator>
      )}
    </NavigationContainer>
  );

}

export default App;

const MainScreen = () => {
  return (
    <Stack.Navigator>
      <Stack.Screen
        name="main"
        component={HM}
        options={{
          headerTitle: 'TripGO',
          headerTitleStyle: {
            fontSize: 24,
            color: 'rgb(182,20,45)',
            fontWeight: 'bold',
          },
        }}
      />
    </Stack.Navigator>
  );
};
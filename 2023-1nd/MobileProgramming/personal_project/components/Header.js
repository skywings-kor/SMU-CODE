import React from 'react';
import { StyleSheet, Text, View } from 'react-native';

export default function Header() {
    return (
        <View style={styles.header}>
            <Text style={styles.title}> 일정 플래너</Text>
            <Text style={styles.title}> (제작자: 2019243064 박규민)</Text>
        </View>
    )
}

const styles = StyleSheet.create({
    header:{
        width:300,
        height:60,
        paddingTop:0,
        backgroundColor:'skyblue'
    },
    title: {
        textAlign:'center',
        color:'#fff',
        fontSize:20,
        fontWeight:'bold',
    }
})
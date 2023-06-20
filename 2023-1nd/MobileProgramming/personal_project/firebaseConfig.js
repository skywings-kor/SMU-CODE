import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";

//다른 프로젝트에서 하던 것을 사용합니다!(서울 공공데이터 포털 & 대학 해커톤 feat. 박규민)
import {onAuthStateChanged , getAuth,createUserWithEmailAndPassword, signInWithEmailAndPassword, sendPasswordResetEmail  } from 'firebase/auth';

import {getFirestore,doc, setDoc,collection, addDoc,getDoc, query, orderBy, limit, getDocs, updateDoc,serverTimestamp,deleteDoc,runTransaction,where,Timestamp,onSnapshot } from 'firebase/firestore'

// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
  
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const firestoreDB = getFirestore(app);
const firebaseAuth = getAuth(app);

export {firestoreDB,firebaseAuth,signInWithEmailAndPassword,createUserWithEmailAndPassword,setDoc,getDoc,addDoc,doc,serverTimestamp,collection, orderBy, limit,where,query,Timestamp,getDocs,onSnapshot,deleteDoc };

import React, { useState, useEffect } from 'react';
import { View, FlatList, Image, Dimensions } from 'react-native';

import storage from '@react-native-firebase/storage';

async function fetchDogImages() {
  const imageRefs = await storage().ref('dogs').listAll();
  const downloadURLs = await Promise.all(
    imageRefs.items.map(itemRef => itemRef.getDownloadURL())
  );
  return downloadURLs;
}

const Home = () => {

  const [images, setImages] = useState([]);

  useEffect(() => {
    async function loadImages() {
      const dogImages = await fetchDogImages();
      setImages(dogImages);
    }
    loadImages();
  }, []);

  const numColumns = 2;
  const size = Dimensions.get('window').width / numColumns;

  return (
    <>
      <ScrollView>
        <FlatList
        data={images}
        renderItem={({ item }) => (
          <View style={{ flex: 1, flexDirection: 'column', margin: 1 }}>
            <Image source={{ uri: item }} style={{ width: size, height: size }} />
          </View>
        )}
        keyExtractor={(item, index) => index.toString()}
        numColumns={numColumns}
      />
      </ScrollView>
    </>
  );
};

export default Home;
import { query, collection, where, getDocs, orderBy, limit,Timestamp,firebaseAuth } from '../firebaseConfig';


const getUpcomingTodos = async (userDocRef) => {
    const dateDocRef = collection(userDocRef, 'dates');
    const currentDate = Timestamp.now();
    




    const q = query(
        dateDocRef,
        where('date', '>=', currentDate),
        orderBy('date'),
        limit(1)
    );

  const querySnapshot = await getDocs(q);
  const upcomingTodos = [];

  querySnapshot.forEach((doc) => {
    const todo = {
      id: doc.id,
      ...doc.data(),
    };
    upcomingTodos.push(todo);
  });

  return upcomingTodos;
};
export default getUpcomingTodos
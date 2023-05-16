import React from 'react'
import { StyleSheet, Text, View, Image, TextInput, TouchableOpacity } from 'react-native';

export default function App() {
  const [fiboIndex, setFiboIndex] = React.useState(0)
  const [numInput, setNumInput] = React.useState('0')
  
  const fibonacci = (index) => {
    if(index==0 || index==1) return index
    else return fibonacci(index-1) + fibonacci(index-2)
  }
  const computeFibo = () => setFiboIndex(fibonacci(numInput))
  return (
    <View style={styles.container}>
      <Image resizeMode="contain" style={styles.fiboImg} source={require('./assets/fibonacci.png')}/>
      <TextInput 
        style={styles.input}
        onChangeText={setNumInput}
        value={numInput}
        placeholder='Informe o valor do termo'
        inputMode='numeric'
      />
      <TouchableOpacity 
        onPress={computeFibo}
        title="CALCULAR"
        style={styles.button}
      >
        <Text style={{color: 'white'}}>CALCULAR</Text>
      </TouchableOpacity>
      <Text style={styles.mainText}>{fiboIndex}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
  fiboImg: {
    width: '75%',
    height: 200,
    marginBottom: 30
  },
  input: {
    borderWidth: 0.5,
    width: '72.5%',
    textAlign: 'center'
  },
  button: {
    padding:10,
    margin:10,
    borderRadius:4,
    width: '72.5%',
    backgroundColor: '#2296f3',
    alignItems: 'center',
  },
  mainText: {
    fontSize:30,
    fontWeight: 'bold'
  }

});

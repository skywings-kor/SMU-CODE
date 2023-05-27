import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import '@chatscope/chat-ui-kit-styles/dist/default/styles.min.css'
import {MainContainer, ChatContainer, MessageList, Message,MessageInput,TypingIndicator} from "@chatscope/chat-ui-kit-react"

const API_KEY="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"

function App() {

  const [typing,setTyping]=useState(false)

  const [messages, setMessages] = useState([
    {
      message:"지피티 API 입니다",
      sender:"ChatGPT"
    }
  ])
  
   const handleSend = async(message)=>{
    const newMessage={
      message:message,
      sender: "user",
      direction:"outgoing"
    }

    const newMessages=[...messages, newMessage];

    setMessages(newMessages)

    setTyping(true)
    
    await processMessageToChatGPT(newMessages)
  }

   async function processMessageToChatGPT(chatMessages){

    let apiMessages = chatMessages.map((messageObject)=> {
      let role=""
      
      if(messageObject.sender==="ChatGPT")
      {
        role="assistant"
      }
      else{
        role="user"
      }

      return {role:role, content:messageObject.message}
    })

    const systemMessage={
      role:"system",
      content:"Explain all concepts like I am 10 years old."
    }

    const apiRequestBody={
      "model":"gpt-3.5-turbo",
      "messages":[
        systemMessage,
        ...apiMessages]
    }

    await fetch("https://api.openai.com/v1/chat/completions",{
      method:"POST",
      headers:{
        "Authorization":"Bearer "+API_KEY,
        "Content-Type":"application/json"
      },

      body: JSON.stringify(apiRequestBody)



    }).then((data)=> {
      return data.json()
    }).then((data)=>{
      console.log(data)
      console.log(data.choices[0].message.content)
      setMessages(
        [...chatMessages, {
          message:data.choices[0].message.content,
          sender:"ChatGPT"
        }]
      )
      setTyping(false)
    })
  }



  return (
      <div className="App">
        <div style={{position: 'relative', height:"800px",width:'700px'}}>
          <MainContainer>
            <ChatContainer>
              <MessageList
                // TypingIndicator={typing ? <TypingIndicator content="챗 지피티가 입력중..."/>:null}
              >
                {messages.map((message,i)=>{
                  return <Message key={i} model={message}/>
                })}
              </MessageList>
              <MessageInput placeholder ='여기에 입력하여주세요' onSend={handleSend}/>
            </ChatContainer>
          </MainContainer>
        </div>
      </div>
  )
}

export default App

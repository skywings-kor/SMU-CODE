from flask import Flask, request, jsonify
from flask_cors import CORS
import openai
from fuzzywuzzy import process

# 자신만의 Key 입력
openai.api_key = ''


app = Flask(__name__)
CORS(app)

qa_pairs = [
    {"question": "이 앱은 어떻게 사용하나요?", "answer": "시민들이 주인이 있을 것 같은 유기 동물을 찍어서 등록하는 시스템입니다."},
    {"question": "이걸로 무엇을 할 수 있어요?", "answer": "이 앱을 통하여 시민들간의 정보 공유로 자신이 잃어버린 동물을 찾을 수가 있습니다."},
    {"question": "고객센터 연락처를 알려주세요.", "answer": "고객센터는 pkm229125@naver.com으로 부탁드립니다."},
    {"question": "이 앱의 제작자는 누구야.", "answer": "선문대학교 박규민 학생입니다."},
    {"question": "이 앱을 만든 목적은 뭐야.", "answer": "모바일 프로젝트 수업에서 개인 프로젝트를 수행하기 위함입니다."},
]


questions = [pair["question"] for pair in qa_pairs]
answers = {pair["question"]: pair["answer"] for pair in qa_pairs}

@app.route('/chatbot_serv', methods=['POST'])
def reply_message():
    user_question = request.json.get('message', '')  # 사용자로부터의 질문을 받아옵니다.

    # 가장 유사한 질문을 찾습니다.
    closest_question, score = process.extractOne(user_question, questions)
    
    if score > 60:
        reply = answers[closest_question]
    else:
        # OpenAI GPT-3의 채팅 형식을 사용하여 답변 생성
        messages = [
            {"role": "system", "content": "You are a customer employee of an abandoned animal-related app."},
            {"role": "user", "content": user_question}
        ]
        
        response = openai.ChatCompletion.create(
          model="gpt-3.5-turbo", 
          messages=messages
        )
        
        reply = response['choices'][0]['message']['content'].strip()

    return jsonify({"reply": reply})

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')
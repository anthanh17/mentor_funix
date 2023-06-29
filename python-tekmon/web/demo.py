import openai
import streamlit as st

view = """
Chào mừng bạn đến với AnThanh! Bạn cảm thấy mệt mỏi khi phải vật lộn để tự viết code
Đừng lo đã có AnThanh ở đây ! Mình sẽ là người giúp bạn viết code với nhiều nhiều ngôn ngữ lập trình khác.
Cho dù bạn là nhà phát triển có nhiều kinh nghiệm hay mới bắt đầu,
AnThanh là nơi hoàn hảo để nhận trợ giúp mà bạn cần.
Còn chờ gì nữa ! Bắt đầu sử dụng AnThanh ngay và luôn
"""

st.markdown("<h1 style='text-align: center;'>AnThanh ✨</h1>", unsafe_allow_html=True)
st.markdown("---")
with st.sidebar:
    st.image("logo.png")
    st.title("Anonyviet")
    st.caption(f'''{view}''', unsafe_allow_html=False)

language=st.selectbox("Lựa chọn 1 ngôn ngữ mà bạn muốn:", ("Python", "C++", "Java", "Pascal"))
question=st.text_area("Nhập câu hỏi của bạn ở bên dưới")
button=st.button("Send")

def answer(question):
    openai.api_key="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" # API KEY
    response = openai.Completion.create(
        model="text-davinci-003",
        prompt=f"""{question} {language}""",
        temperature=0,
        max_tokens=1024,
        top_p=1,
        frequency_penalty=0,
        presence_penalty=0
        )
    return response.choices[0].text

if question and button:
    with st.spinner("Đợi chút nhen !"):
        reply=answer(question)
        st.code(reply)
        button2=st.button("Clear")

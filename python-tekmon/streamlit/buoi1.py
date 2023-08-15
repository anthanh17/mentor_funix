import streamlit as st
import time

# st.write("hello world")
# st.title ("this is the app title")
# st.header("this is the markdown")
# st.markdown("this is the header")
# st.subheader("this is the subheader")
# st.caption("this is the caption")
# st.code("x=2021")
# st.latex(r''' a+a r^1+a r^2+a r^3 ''')

# st.image("a.jpg")
# st.audio("https://radiotruyen.info/kiem-hiep/ngoa-ho-tang-long-1-snv.html")
# st.video("https://www.youtube.com/watch?v=y576-ONm5II&list=RDMMCHoEqjAepPE&index=3&ab_channel=JenHoang")
# ####
# b = st.checkbox('yes')
# b = st.checkbox('no')
# a = st.button('Click')
# c = st.radio('Pick your gender',['Male','Female'])

# st.selectbox('Pick your gender',['Male','Female', "test"])
# st.multiselect('choose a planet',['Jupiter', 'Mars', 'neptune'])

# st.select_slider('Pick a mark', ['Bad', 'Good', 'Excellent'])
# d = st.slider('Pick a number', 0,50)
# print("annt: ", d)
####
# st.number_input('Pick a number', 0,10)
# st.text_input('Email address')
# st.date_input('Travelling date')
# st.time_input('School time')
# st.text_area('Description')
# st.file_uploader('Upload a photo')
# st.color_picker('Choose your favorite color')
####
st.balloons()
for i in range(100):
    st.progress(i+10)
    time.sleep(1)
with st.spinner('Wait for it...'):
    time.sleep(10)
#####
# st.success("You did it !")
# st.error("Error")
# st.warnig("Warning")
# st.info("It's easy to build a streamlit app")
# st.exception(RuntimeError("RuntimeError exception"))
####


# st.sidebar.write("hello world")
# st.sidebar.title ("this is the app title")
# st.sidebar.header("this is the markdown")
# st.sidebar.markdown("this is the header")
# st.sidebar.subheader("this is the subheader")
# st.sidebar.caption("this is the caption")
# st.sidebar.code("x=2021")
# st.sidebar.latex(r''' a+a r^1+a r^2+a r^3 ''')

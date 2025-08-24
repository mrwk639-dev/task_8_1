# استخدم صورة Ubuntu
FROM ubuntu:20.04

# منع الأسئلة أثناء التثبيت
ENV DEBIAN_FRONTEND=noninteractive

# تحديث النظام + تثبيت g++
RUN apt-get update && apt-get install -y g++

# حدد مجلد العمل
WORKDIR /app

# انسخ الملفات من جهازك للكونتينر
COPY . .

# كومبايل الكود
RUN g++ -o my_app ind_8.cpp

# شغل البرنامج
CMD ["./my_app"]

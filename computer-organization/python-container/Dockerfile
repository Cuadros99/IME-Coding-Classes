FROM ubuntu:focal

# RUN command to install the necessary dependencies
RUN apt-get update
RUN apt-get install python3 -y
RUN apt-get install pip -y
RUN pip install numpy 

# Directory with the language test files
ADD  python_env_perfomance_test-main /home

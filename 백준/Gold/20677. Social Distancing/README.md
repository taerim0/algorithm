# [Gold I] Social Distancing - 20677 

[문제 링크](https://www.acmicpc.net/problem/20677) 

### 성능 요약

메모리: 5548 KB, 시간: 280 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2023년 10월 22일 00:31:46

### 문제 설명

<p>Leila is a surgeon in a high-quality hospital. To reach the operating room, she has to pass through a waiting saloon, where some patients with Coronavirus symptoms are waiting to get tested. To avoid the infection, Leila wants to pass through the saloon in such a way that she keeps the maximum distance from the patients. Your task is to help her find the maximum possible distance from any patient while passing through the waiting saloon. You are given the map of the saloon as a matrix, in which the locations of the patients and the free seats (where she can not pass through!) are marked. The distance of two cells (x<sub>1</sub>, y<sub>1</sub>) and (x<sub>2</sub>, y<sub>2</sub>) in the matrix is defined as max(|x<sub>1</sub> − x<sub>2</sub>|, |y<sub>1</sub> − y<sub>2</sub>|). Seats do not block corona from spreading. Thus, in the definition of the distance between two cells, we do not consider the places of the seats. In each step, Leila can go from one cell in the matrix to one of its four neighbors: up, down, right, and left in the saloon, if no seats and patients are there.</p>

### 입력 

 <p>The first line of the input consists of two integers m (1 ⩽ m ⩽ 500) and n (1 ⩽ n ⩽ 500) separated by a space, which is the number of rows and the number of columns, respectively. Then, the map of the waiting saloon is given in m following lines; each line represents a row of the matrix and contains n characters, “<code>*</code>” is for a patient, “<code>#</code>” for an empty seat, and “<code>.</code>” for free space where Leila can walk through. The starting point of Leila is represented by an “<code>S</code>” character, and the endpoint of her path is represented by an “<code>E</code>” character in the matrix. Note that Leila cannot go out of the saloon (which is represented as the matrix) in her path.</p>

### 출력 

 <p>Print the maximum possible distance which Leila can maintain from the patients in her path. If it is not possible for Leila to reach the operating room at all, print a “<code>-1</code>” in the output. Otherwise, if no patient is present in the saloon, print “<code>safe</code>” in the output.</p>


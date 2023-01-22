# ✅ Exam_Rank-06
The aim of the project is to create a simple server where client can connect and exchange messages.
## Compilation
Server:
```
cd rendu
make
```
## Usage
Client:
```
nc 127.0.0.1 6000
```
## Example
## Usage
Client 0:
```
nc 127.0.0.1 6000
```
## Usage
Client 1:
```
nc 127.0.0.1 6000
Hello, client 0!
```
## Usage
Client 2:
```
nc 127.0.0.1 6000
Hello, client 0 and client 1!
```
## Usage
Client 0
```
Goodbye, client 1 and client 2!
```
## Usage
Client 1:
```
Goodbye, client 2!
```
## Output
Client 0:
```
server: client 1 just arrived
client: 1: Hello, client 0!
server: client 2 just arrived
client: 2: Hello, client 0 and client 1!
```
## Output
Client 1:
```
server: client 2 just arrived
client: 2: Hello, client 0 and client 1!
client: 0: Goodbye, client 1 and client 2!
server: client 0 just left
```
## Output
Client 2:
```
client: 0: Goodbye, client 1 and client 2!
server: client 0 just left
client: 1: Goodbye, client 2!
server: client 1 just left
```
## Resources
- [Subjects](https://github.com/markveligod/examrank-02-03-04-05-06/tree/master/examRank06/subjects/mini_serv)
- [Подготовка к Exam Rank 06 (Финальный экзамен в Школе 21)](https://www.youtube.com/watch?v=8yGea5tK6oQ)
- [mini_serv.c](https://github.com/Nike2406/ft_exams/tree/main/exam06)

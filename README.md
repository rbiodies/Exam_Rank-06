# ✅ Exam_Rank-06
### The aim of the project:
To create a simple server where client can connect and exchange messages.
### Run:
Server:
```
$>cd rendu
$>make
```
Client:
```
$>nc 127.0.0.1 6000
```
### Example:
Client 0:
```
$>nc 127.0.0.1 6000
server: client 1 just arrived
server: client 2 just arrived
Goodbye!
```
Client 1:
```
$>nc 127.0.0.1 6000
server: client 2 just arrived
client: 0: Goodbye!
server: client 0 just left
```
Client 2:
```
$>nc 127.0.0.1 6000
client: 0: Goodbye!
server: client 0 just left
server: client 1 just left
```
### Useful links:
- [Subjects](https://github.com/markveligod/examrank-02-03-04-05-06/tree/master/examRank06/subjects/mini_serv)
- [Подготовка к Exam Rank 06 (Финальный экзамен в Школе 21)](https://www.youtube.com/watch?v=8yGea5tK6oQ)

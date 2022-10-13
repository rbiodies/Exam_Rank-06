# ✅ Exam_Rank-06
### The aim of the project:
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
Hello, Guys!
```
Client 1:
```
$>nc 127.0.0.1 6000
server: client 2 just arrived
client: 0: Hello, Guys!
server: client 0 just left
```
Client 2:
```
$>nc 127.0.0.1 6000
client: 0: Hello, Guys!
server: client 0 just left
server: client 1 just left
```

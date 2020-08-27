# Secure-File-Transfer <img src="https://github.com/NikhilMishra1999/Secure-File-Transfer/blob/master/AES/SS/secure.png" height="200" align="right"> 
We developed a channel to transfer files securely, using key based encryption methods and comparing the different methods on Linux based OS. The sub-objectives incidental to the main objective are:
>	- Use of Asymmetric and Symmetric encryption methods to secure both ends of the communication channel
>	- To provide a secure channel for faster transmission of data
>	- To build a dependable and encrypted file transfer system between client and server
>	- To compare the asymmetric and symmetric encryption algorithms.
 ----------------
## Technology Used
> - Linux Based OS (Ubuntu | Kali)
> - C 
> - Socket Programming

 ----------------
### RSA ENCRYPTION
> RSA algorithm is a public key encryption technique and is considered as the most secure way of encryption. It was invented by Rivest, Shamir and Adleman in year 1978 and hence name RSA algorithm.
> - The RSA algorithm holds the following features −
> 1. RSA algorithm is a popular exponentiation in a finite field over integers including prime numbers.
> 2. The integers used by this method are sufficiently large making it difficult to solve.
> 3. There are two sets of keys in this algorithm: private key and public key.
<img src="https://raw.githubusercontent.com/NikhilMishra1999/Secure-File-Transfer/master/RSA/SS/client1.png" height="100" width="300" align="center">
<img src="https://raw.githubusercontent.com/NikhilMishra1999/Secure-File-Transfer/master/RSA/SS/client2.png" height="100" width="300" align="center">
<img src="https://raw.githubusercontent.com/NikhilMishra1999/Secure-File-Transfer/master/RSA/SS/server1.png" height="100" width="300" align="center">
<img src="https://raw.githubusercontent.com/NikhilMishra1999/Secure-File-Transfer/master/RSA/SS/server2.png" height="100" width="300" align="center">

 ----------------
### AES ENCRYPTION
> The more popular and widely adopted symmetric encryption algorithm likely to be encountered nowadays is the Advanced Encryption Standard (AES). It is found at least six time faster than triple DES. A replacement for DES was needed as its key size was too small. With increasing computing power, it was considered vulnerable against exhaustive key search attack. Triple DES was designed to overcome this drawback but it was found slow.
> - The features of AES are as follows −
> 1. Symmetric key symmetric block cipher
> 2. 128-bit data, 128/192/256-bit keys
> 3. Stronger and faster than Triple-DES
> 4. Provide full specification and design details
> 5. Software implementable in C and Java
<img src="https://raw.githubusercontent.com/NikhilMishra1999/Secure-File-Transfer/master/AES/final%20SS/Aes1.png" height="100" width="300" align="center">
<img src="https://raw.githubusercontent.com/NikhilMishra1999/Secure-File-Transfer/master/AES/final%20SS/Aes2.png" height="100" width="300" align="center">
<img src="https://raw.githubusercontent.com/NikhilMishra1999/Secure-File-Transfer/master/AES/final%20SS/Aes3.png" height="100" width="300" align="center">
 
 ----------------
## Limitations
1. It can only encrypt text files.

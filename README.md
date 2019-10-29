GSURF - Teste TCP/IP

Este projeto tem o objetivo de demonstrar as aptidões do programador Ricardo Villela Coppola na linguagem C++.
O desenvolvimento foi realizado com o uso do Embarcadero C++ Builder 10.3.2 Community Edition.
O projeto é consistido de uma aplicação servidora e uma aplicação cliente.
Estas se comunicam via TCP/IP usando o endereço local 127.0.0.1 e a porta 175.
A aplicação cliente deve montar uma expressão matemática simples usamdo as quatro operações básicas: soma(+), subtração(-),
miltiplicação(*) e divisão(/).
As parcelas podem ser inteiras ou com ponto flutuante. O divisor decimal, se usado, deve ser o caracter '.'. Não devem ser usados
espaços entre as pareclas e os sinais das operações.
Depois de montada a expressão desejada, esta pode ser transmitida ao servidor via botão "Enviar".
Ao receber a expressão, o servidor mostrará a sua decomposição e solução, retornando apenas a última ao cliente.
Em caso de receber uma expressão inválida, o servidor enviará uma mensagem destacando o tipo do erro e a sua posição no texto da
expressão recebida. Multiplicação e divisão têm precedência sobre adição e subtração, fora isso, as expressões são avaliadas
da esquerda para a direita.

This project is intended to serve as a demonstration of the programming abilities of Ricardo Villela Coppola in the C++ language.
The development has been done using the Embarcadero C++ Builder 10.3.2 Community Edition.
It consists of a server application and a client one. They communicate with each-other via TCP/IP using the address 127.0.0.1 and
the port 175.
The client application should mount a simple mathematical expression using the four basic operations: addition(+), subtraction(-),
multiplication(*) and division(/).
The operands can be integer or floating point values. The decimal divisor, if used, mustbe the '.' character. Spaces might NOT be
used between the operator signals and the operands.
After been mounted the desired expression can be transmitted to the server via the "Send" button.
Upon receiving an expression the server application will show its decomposition and solution returning the later to the client.
In case of an invalid expression the server will send a message highlighting the kind and position of the error in the received
expression. Multiplication an division have precedence over adition and subtraction, otherwise, the expressions are avaliated from
left to write.

Ex.: 124+456*41/6

P.S.: I apologize for having the comments inside the code written in Brazilian Portuguese, but the intention of the project is to
serve as a demonstration of my abilities the assume a job position.

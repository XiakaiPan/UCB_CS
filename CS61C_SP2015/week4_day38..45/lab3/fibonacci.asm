.data
msg1:			.asciiz "Entre com um numero: "
n:   			.word 0
primeiro_valor: 	.word 0
segundo_valor: 	.word 1
proximo: 		.word 0
i: 			.word 1
.text
.globl main
main:

li $v0,4 		#Carrega o codigo de imprimir em $v0
la $a0, msg1       #carrega o endere?o de memoria da vari¨¢vel msg1 
syscall                 #chama o S.O para realizar a opera??o
#li $s3,1

li $v0, 5               #Carrega o c¨®digo de ler inteiro I/O
syscall         
sw $v0, n            #Salva o conte¨²do do que foi digitado pelo teclado

la $t1, i              #carrega o endere?o da label i no registrador $t1
la $t2, n              #Carrega o endere?o da label n no registrador $t2

lw $t3, ($t1)          # carrega a palavra no endere?o do registrador $t1
lw $t4, ($t2)          # carrega a palavra no endere?o do registrador $t2

#li $t5, 1              # Carrega o valor 1 em $t5

la $t5, primeiro_valor  #Carrega o endere?o da word "primeiro_valor"
la $t6, segundo_valor    #Carrega o endere?o da word "segundo_valor"
la $t7, proximo          # Carrega o endere?o da word "proximo"

lw $s0,($t5)              #Carrega o conteudo dos registradores preenchidos no bloco anterior
lw $s1,($t6)
lw $s2,($t7)

loop:
beq $t3, $t4, final         # se i = n vai pra label final
addi $t3,$t3,1              #incrementa o contador
ble $t3,$t4, recebe1        # se i for menor ou igual a n, pula pra label recebe1


recebe1:                      #proximo recebe 1
add $s2,$t3,$zero             
j loop                        #pula para o loop

senao:                        # senao
add $s2,$s0,$s1
add $s0,$s1,$zero
add $s1,$s2,$zero
j loop

final:
li $v0,1 		#Carrega o codigo de imprimir em $v0
la $a0,($s1)
syscall                 #chamada do S.O para executar a operacao

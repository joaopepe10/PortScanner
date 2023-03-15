import socket #Importei a biblioteca que trata da placa de rede, que faz comunicacao da placa de rede com o SO

ip = str(input("Digite o host ou ip a ser verificado: "))
quantidade_de_portas = int(input("Digite a quantidade de portas que voce deseja verificar: "))
portas = []
cont = 0

while cont < quantidade_de_portas:
    portas.append(int(input("Digite qual a porta voce deseja fazer a verificacao: ")))  #Aqui eu adc as portas ao vetor
    cont+=1

for port in portas:
    cliente = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # dentro do metodo de conexao eu preciso declarar qual tipo de conexao irei fazer, exemplo: UDP, IPV6, TCP, IPV4
    # QUANDO EU TRABALHO COM METODO INET E PQ ESTOU TRABALHANDO COM METODO IPV4, JA O SOCK_STREAM E O MODO DE CONEXAO TCP
    cliente.settimeout(
        0.05)  # funcao utilizada para diminuir o tempo que a requisicao vai bater na porta desejada, fazendo assim o programa ficar mais rapido
    code = cliente.connect_ex((ip, port))
    # variavel CODE ira receber um codigo da transacao TCP
    if code == 0:
        print(f"PORTA -> {port} ABERTA!")
    else:
        print(f"PORTA -> {port} ABERTA!")
print("SCAN FINALIZADO!")
# Global-Solution-Edge-Computing

# ORBIT AGRO 
Sistema Inteligente de Irrigação por Gotejamento

O Orbit Agro é um sistema de monitoramento agrícola desenvolvido para auxiliar no controle da irrigação por gotejamento de forma automatizada e inteligente, o projeto utiliza sensores para monitorar as condições do ambiente e do solo em tempo real, permitindo identificar quando uma planta necessita de irrigação, por meio da análise da umidade do solo, temperatura do ambiente, umidade do ar e intensidade luminosa, o sistema fornece alertas visuais e sonoros e simula o acionamento de um sistema de irrigação utilizando um LED azul. O objetivo é otimizar o uso da água, reduzir desperdícios e auxiliar pequenos produtores no monitoramento das condições ideais para o cultivo.

Wokwi: https://wokwi.com/projects/465647591568752641

Video apresentação: 

---
# Funcionalidades

O sistema realiza a leitura contínua de:

- Umidade do Solo (Potenciômetro)
- Temperatura Ambiente (DHT22)
- Umidade do Ar (DHT22)
- Luminosidade (LDR)

Com base nesses dados, o sistema classifica automaticamente as condições do cultivo e exibe informações no LCD

---
# Monitoramento da Umidade do Solo

O potenciômetro é utilizado para simular um sensor de umidade do solo.

Solo Úmido ----} LED Verde 🟢  
- Umidade do solo acima de 60%
- Irrigação desligada
- Ambiente considerado adequado

Solo Moderado ----} LED Amarelo 🟡
- Umidade do solo entre 30% e 60%
- Atenção preventiva
- Irrigação desligada

Solo Seco ----} LED Vermelho 🔴 e LED Azul (Irrigação) 🔵
- Umidade solo abaixo de 30%
- Sistema entra em modo de irrigação
- LED azul representa a bomba de irrigação acionada

---
# Irrigação Inteligente

O sistema também considera a luminosidade do ambiente para determinar a prioridade da irrigação.

Solo seco + luminosidade alta
- O LCD exibe: Irrig.Imediato
  
Indicando que a planta está sob forte incidência de luz e necessita de irrigação urgente.

Solo seco + luminosidade média ou baixa
- O LCD exibe: Irrigando...

Indicando que a irrigação foi iniciada normalmente.

---
# Monitoramento de Temperatura

Realizado através do sensor DHT22.

Temperatura Baixa = Menor que 20°C
- LCD: Temp: XXC - Baixa

Temperatura ideal = Entre 20°C e 30°C
- LCD: Temp: XXC - Ideal

Temperatura Alta = Acima de 30°C
- LCD: Temp: XXC - Alta

---
# Monitoramento da Umidade do Ar

Também realizado pelo sensor DHT22.

O LCD apresenta continuamente a umidade relativa do ar:

Exemplo ----} Ar: 65%

Essas informações auxiliam no acompanhamento das condições ambientais da plantação.

---
# Monitoramento de Luminosidade

O sensor LDR realiza a leitura da intensidade luminosa do ambiente.

O sistema classifica a luminosidade em:

- Baixa = Luz: Baixa
- Ideal = Luz: Ideal
- Alta = Luz: Alta

Essas informações são exibidas na segunda tela do LCD juntamente com os dados de temperatura e umidade do ar.

---
# Sistema de Alertas

LED Verde
Indica:
- Solo úmido
- Condição adequada

LED Amarelo
Indica:
- Solo moderadamente úmido
- Atenção preventiva

LED Vermelho
Indica:
- Solo seco
- Necessidade de irrigação

LED Azul
Indica:
- Sistema de irrigação acionado

Buzzer
Ao detectar solo seco:
- 🔊 Emite um único aviso sonoro
- O buzzer não permanece ligado continuamente, evitando poluição sonora e consumo desnecessário de energia

---
# Display LCD

O sistema utiliza um display LCD 16x2 para exibição das informações em duas telas alternadas.

Tela A – Status do Solo
Exemplo:
- Solo:25%
- Irrig.Imediato
  
ou

- Solo:45%
- Solo Moderado

ou

- Solo:80%
- Solo Umido
  
Tela B – Ambiente
Exemplo:
- Temp:24C - Ideal
- Ar:65% Luz:Ideal

Nesta tela são exibidas:
  - Temperatura
  - Umidade do ar
  - Luminosidade

---
# Hardware Utilizado

- 1x Arduino Uno
- 1x Sensor DHT22
- 1x Sensor LDR
- 1x Potenciômetro (simulando sensor de umidade do solo)
- 1x Display LCD 16x2
- 1x LED Verde
- 1x LED Amarelo
- 1x LED Vermelho
- 1x LED Azul
- 1x Buzzer
- 1x Protoboard
- Cabos Jumper

---
# Como Executar

1. Montagem: 

Conecte os componentes conforme o diagrama desenvolvido no Wokwi.

2. Instalação das Bibliotecas:

Instale na Arduino IDE:
- DHT Sensor Library
- LiquidCrystal

3. Upload:

Abra o arquivo .ino e envie o código para a placa Arduino.

4. Testes:

Para testar:
- Ajuste o potenciômetro para simular a umidade do solo.
- Modifique os valores do DHT22 para alterar temperatura e umidade do ar.
- Altere a luminosidade do LDR.

Observe:
- LEDs
- Buzzer
- LED Azul (irrigação)
- LCD
- Monitor Serial

---
# Equipe Desenvolvedora:
- Augusto Torin
- Fabricio Mendoza
- Felipe Peres
- Julia da Silva
- Thiago Silva

*Projeto desenvolvido como requisito de avaliação acadêmica.*












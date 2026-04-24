# 💳 Validador de Cartão de Crédito

## 📌 Descrição

Programa em C que valida números de cartões de crédito utilizando o algoritmo de Luhn e identifica a bandeira (VISA, AMEX ou MASTERCARD).

---

## ⚙️ Funcionamento

O programa segue três etapas:

### 1. Entrada

O usuário insere o número do cartão de crédito.

### 2. Validação (Algoritmo de Luhn)

* Dígitos alternados são multiplicados por 2
* Os resultados são somados (considerando dígitos individuais)
* Soma total é validada (deve terminar em 0)

Se falhar:

```bash
INVALID
```

### 3. Identificação da bandeira

Com base no número e quantidade de dígitos:

* **VISA** → começa com 4 (13 ou 16 dígitos)
* **AMEX** → começa com 34 ou 37 (15 dígitos)
* **MASTERCARD** → começa entre 51 e 55 (16 dígitos)

---

## 🧠 Conceitos aplicados

* Manipulação de números inteiros (`long`)
* Operações matemáticas (`%` e `/`) para extração de dígitos
* Estruturas de repetição (`while`)
* Validação de dados com algoritmo de Luhn

---

## ▶️ Como executar

Compile:

```bash
make credit
```

Execute:

```bash
./credit
```

---

## 📚 Contexto

Desafio prático do curso CS50, focado em lógica de programação e manipulação de dados numéricos em baixo nível.

---

## 🚀 Possíveis extensões

* Suporte a outras bandeiras
* Validação de entrada mais robusta
* Interface interativa

---

## 🏁 Resultado

O programa retorna:

* `VISA`
* `AMEX`
* `MASTERCARD`
* `INVALID`

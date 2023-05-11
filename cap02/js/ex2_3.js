const frm = document.querySelector('form')
const outNome = document.querySelector('#outNome')
const outEntrada = document.querySelector('#outEntrada')
const out12x = document.querySelector('#out12x')

frm.addEventListener("submit", (e) => {
    const nome = frm.inNome.value
    const preco = Number(frm.inPreco.value)

    const entrada = preco*0.5
    const parcela = (preco-entrada)/12

    outNome.innerText = `Promoção: ${nome}`
    outEntrada.innerText = `Entrada de: R$ ${entrada.toFixed(2)}`
    out12x.innerText = `+12x de R$ ${parcela.toFixed(2)}`

    e.preventDefault()
})
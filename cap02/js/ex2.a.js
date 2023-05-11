const frm = document.querySelector('form')
const outNome = document.querySelector('#outNome')
const outResp = document.querySelector('#outResp')

frm.addEventListener("submit", (e) => {
    const nome = frm.inNome.value
    const preco = Number(frm.inPreco.value)

    const valor = Math.floor(preco*2)

    outNome.innerText = `Promoção de ${nome}`
    outResp.innerText = `Leve 2 por apenas R$ ${valor.toFixed(2)}`

    e.preventDefault()
})
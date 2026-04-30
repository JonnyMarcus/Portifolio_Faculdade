from reportlab.lib.pagesizes import A4
from reportlab.pdfgen import canvas


def exportar_pdf(conteudo):
    arquivo = "historico_matematica_discreta.pdf"

    pdf = canvas.Canvas(arquivo, pagesize=A4)

    largura, altura = A4

    y = altura - 50

    pdf.setFont("Helvetica", 12)

    for linha in conteudo.split("\n"):
        pdf.drawString(50, y, linha)
        y -= 20

    pdf.save()

    return arquivo
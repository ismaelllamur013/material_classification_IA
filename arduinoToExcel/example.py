from serialToExcel import SerialToExcel

serialToExcel = SerialToExcel("COM3",115200)

columnas = ["Nro Lectura","Valor_R","Valor_V","Valor_A"]

serialToExcel.setColumns(["Nro Lectura","Valor_R","Valor_V","Valor_A"])
serialToExcel.setRecordsNumber(5000)
serialToExcel.readPort()

serialToExcel.writeFile("andes_negra.xls")

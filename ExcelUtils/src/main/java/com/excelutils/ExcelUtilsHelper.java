package com.excelutils;

import org.apache.poi.ss.usermodel.*;

public class ExcelUtilsHelper {
    public static void createCellHeader(Row row, int columIndex, Object name)
    {
        Cell cell = row.createCell(columIndex);
        if (name instanceof String)
        {
            cell.setCellValue((String) name);  // Si es un String
        }
        else if (name instanceof Integer)
        {
            cell.setCellValue((Integer) name);  // Si es un Integer
        }

    }

    public static  void getStyleHeader(Workbook workbook, Sheet s)
    {
        CellStyle style = workbook.createCellStyle();

        // Establecer formato de texto (negrita)
        Font font = workbook.createFont();
        font.setBold(true);
        font.setColor(IndexedColors.RED.getIndex()); // Rojo
        style.setFont(font);

        //
    }
}

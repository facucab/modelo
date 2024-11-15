package com.excelutils;

import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.Workbook;
import org.apache.poi.ss.util.CellRangeAddress;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

import java.io.FileOutputStream;
import java.io.IOException;

public class ExcelUtils {


    public static Workbook createExcel()
    {
        return  new XSSFWorkbook();
    }

    public static Sheet createSheet(Workbook workbook, String sheetName)
    {
        return  workbook.createSheet(sheetName);
    }

    public  static void saveWorkbook(Workbook workbook, String nameFile) throws IOException {
        try{
            FileOutputStream fileOut = new FileOutputStream(nameFile);
            workbook.write(fileOut);
        }
        catch (IOException e) {
            throw  new IOException("ERROR FILE");
        }
        finally {
            workbook.close();
        }
    }

    public static  void createHeaderStruct(Sheet s)
    {
        //
        String [] Days = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabados", "Domingo"};
        //Primerar filas:
        Row rowFirst = s.createRow(0);
        Row rowSecond = s.createRow(1);


        //crear columnas de la fila 1:
        ExcelUtilsHelper.createCellHeader(rowFirst, 0, "Legajo");
        ExcelUtilsHelper.createCellHeader(rowFirst, 1, "Nombre");

        // segunda fila:
        ExcelUtilsHelper.createCellHeader(rowSecond, 0, " ");
        ExcelUtilsHelper.createCellHeader(rowSecond, 1, " ");

        //cargo dias y horarios
        int i = 2;
        for (String  day: Days)
        {
            ExcelUtilsHelper.createCellHeader(rowFirst, i, day);


            for(int j = 0; j < 24; j++)
            {
                ExcelUtilsHelper.createCellHeader(rowSecond, i,  j);
                i++;
            }
        }

        //Fusionar celdas
        s.addMergedRegion(new CellRangeAddress(0,1, 0,0)); // legajo
        s.addMergedRegion(new CellRangeAddress(0,1,1,1)); // nombre
        s.addMergedRegion(new CellRangeAddress(0,0, 2, 25)); //Lunes
        s.addMergedRegion(new CellRangeAddress(0,0, 26, 49)); //Martes
        s.addMergedRegion(new CellRangeAddress(0,0, 50, 73)); // Miercoles
        s.addMergedRegion(new CellRangeAddress(0,0, 74, 97)); // Jueves
        s.addMergedRegion(new CellRangeAddress(0,0, 98, 121)); // Viernes
        s.addMergedRegion(new CellRangeAddress(0,0, 122, 145)); // Sabado
        s.addMergedRegion(new CellRangeAddress(0,0, 146, 169)); // Domingo

    }
}

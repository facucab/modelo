package com.excelutils;

import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.Workbook;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {

        //creo la hoja de trabajo:
        Workbook workbook = ExcelUtils.createExcel();

        //
        Sheet pageOne = ExcelUtils.createSheet(workbook,"Page 1");

        //
        ExcelUtils.createHeaderStruct(pageOne);

        ExcelUtils.saveWorkbook(workbook, "Archivo.xlsx");
    }
}
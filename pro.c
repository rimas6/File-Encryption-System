#include <stdio.h>  // مكتبة الإدخال والإخراج
#include <stdlib.h> //: مكتبة الدوال العامة زي
                   // exit و malloc

                                                   // ميثود للتشفير وفك التشفير لمحتوى الملف
void encryptDecrypt(char *inputFile, char *outputFile, char key) {
                                                            // نفتح ملف الإدخال للقراءة (بصيغة باينري)   
    FILE *inFile = fopen(inputFile, "rb");
                                                            // نفتح ملف الاخراج  للقراءة (بصيغة باينري) 
    FILE *outFile = fopen(outputFile, "wb");
                                                             // نتأكد إن الملفات فتحوا صح
    if (inFile == NULL || outFile == NULL) {
        printf("Error opening files.\n"); //لو فيه مشكلة في الفتح، نطبع رسالة خطأ
        exit(1); // نخرج من البرنامج
    }

    char ch;// متغير عشان نخزن كل حرف بنقرأه
                                                  // نقرأ كل حرف من ملف الإدخال لحد ما نوصل لنهاية الملف
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch ^ key, outFile);  // نطبق عملية XOR مع المفتاح ونكتب النتيجة في ملف الإخراج   
    }
                                                                          // نقفل ملف الإدخال والاخراج
    fclose(inFile);
    fclose(outFile);
}

int main() {
    char *inputFile = "input.txt";  // اسم ملف الإدخال
    char *outputFile = "output.txt"; // اسم ملف الإخراج
    char key = 'K';                   // مفتاح التشفير

                                                             // نستدعي الميثود عشان نشفر الملف
    encryptDecrypt(inputFile, outputFile, key);
    printf("File encrypted successfully.\n"); // نطبع رسالة ان التشفير نجح

                                             // لفك التشفير، يمكن استدعاء الميثود مرة أخرى بنفس المفتاح
    encryptDecrypt(outputFile, "decrypted.txt", key);
    printf("File decrypted successfully.\n");  // نطبع رسالة ان فك التشفير نجح

    return 0; // نخرج من البرنامج اذا نجح
}

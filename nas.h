//Webupdate from NAS  -----------------------------------------------------------------
#include <ESP8266httpUpdate.h>
#define BOOT_AFTER_UPDATE true  // zorgt er voor dat de esp boot na remote image laden

void WebUpdate(char Download_server []) {

  delay(1000);
  Serial.println();
  Serial.println();
  Serial.println();


  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    show(  "setup wait", String(t));
    Serial.flush();
    delay(1000);
  }
  show(  "software update", "WAIT!!");
  delay(1000);
  ESPhttpUpdate.rebootOnUpdate(BOOT_AFTER_UPDATE);  // true
  // vereenvoudiging voor de gebruiker. Alleen de naam van het bestand.
  String basis =  "http://???????????/" ;  //URL image on the NAS
  char tail [] = ".ino.bin";
  basis.concat(Download_server);
  basis.concat(tail);
  char server_sag [80] = " ";
  basis.toCharArray(server_sag , 80);
  Serial.println(basis);
  t_httpUpdate_return ret = ESPhttpUpdate.update(server_sag);
  switch (ret) {
    case HTTP_UPDATE_FAILED:
      Serial.printf("HTTP_UPDATE_FAILD Error (%d): %s", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
      show(  "http udate fout", ESPhttpUpdate.getLastErrorString().c_str());
      break;

    case HTTP_UPDATE_NO_UPDATES:
      Serial.println("HTTP_UPDATE_NO_UPDATES");
      break;

    case HTTP_UPDATE_OK:
      Serial.println("HTTP_UPDATE_OK");
      break;
  }
}

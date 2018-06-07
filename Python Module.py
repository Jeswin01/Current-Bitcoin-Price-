import scrapy
import serial
import time
AS=serial.Serial('COM4',9600);
time.sleep(2);

class BitSpider(scrapy.Spider):
    name = "bitcoin"
    start_urls = [
        'https://www.ccn.com/bitcoin-price/',
                  ]

    def parse(self, response):
        a=response.css("span#ccnSummaryPriceCurrent::text").extract();
        st=a[0];
        c=1;
        nst=st.replace("$","");
        st=nst.replace(",","");
        nst=st.split(".");
        prh=int(nst[0]);
        prl=int(nst[1]);
        pr=str(prh)+"."+str(prl);
        s=bytes(str(pr),'utf-8');
        AS.write(s);
        delay_time=len(s)+1;
        #print("prh written",pr,": ",s);
        time.sleep(delay_time);
        msg = AS.read(AS.inWaiting()) # read everything in the input buffer
        print ("Message from arduino: ")
        msg=msg[:-2];
        res=msg.decode("utf-8");
        print (res);
        

# Http server (bez vláken)

## Zadání
Úkolem je naprogramovat jednoduchý http server s podporou různých generátorů obsahu. Generátor obsahu může být například 1) externí skript; 2) konkrétní html stránka (statický obsah); 3) výpis obsahu adresáře. HTTP server nemusí umět obsloužit více domén. Server bude konfigurovatelný pomocí souboru. Konfigurovat půjde rozhraní, kde server naslouchá, generovaný log přenosů, kořenový adresář s obsahem. Navíc server může (ale nemusí) umět poskytovat virtuální filesystém. Virtuálním filesystémem se myslí mapování obsahu na konkrétní soubor (generátor obsahu). Tedy např. http://myserver/data ukazuje na adresář /mnt/data http://myserver/index.html ukazuje na soubor /var/cache/apache2/index.html http://myserver/firma1 ukazuje na shellový skript /home/firma1/skript.sh, který vygeneruje obsah.


## Poznámky
- pro výpočet počtu řádků kódu lze použít `find src/ -name '*.cpp' | xargs wc -l`

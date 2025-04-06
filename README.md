# ExpansionBookItem
Source code for the Book Item for DayZ Expansion mod, available at:
https://steamcommunity.com/sharedfiles/filedetails/?id=3459100836

Example Typesfile entry:
Insert the relevant snippet below into your types xml file. This same basic setup should work for all maps. The types file(s) are normally called types.xml or expansion_types.xml, and are located in:
		\DayZServer\mpmissions\(your mission name\db\
or 	\DayZServer\mpmissions\(your mission name\expansion_ce\

	<type name="expBookItem">
        <nominal>30</nominal>
        <lifetime>14400</lifetime>
        <restock>0</restock>
        <min>30</min>
        <quantmin>-1</quantmin>
        <quantmax>-1</quantmax>
        <cost>100</cost>
        <flags count_in_cargo="0" count_in_hoarder="0" count_in_map="1" count_in_player="0" crafted="0" deloot="0"/>
        <category name="tools"/>
    </type>
	
If you want to limit this to certain tiers or locations, your best option is to copy another item with the properties you want to replicate, and then copy-paste that and edit the name to "expBookItem".

If you want to add this to starting loot, one way is to adding it to the "StartingEquipSetup" routine in the init.c file. 	You can find this file in \DayZServer\mpmissions\(your mission name)\init.c Look for the first two lines that adds a bandage to starting gear in all vanilla maps, and insert the new line with expBookItem below that.
	
	// find these two lines in init.c first:
	itemEnt = itemClothing.GetInventory().CreateInInventory( "BandageDressing" );
	player.SetQuickBarEntityShortcut(itemEnt, 2);
	// insert this new line below them:
	itemEnt = itemClothing.GetInventory().CreateInInventory( "expBookItem" );

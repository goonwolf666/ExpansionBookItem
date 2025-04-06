class CfgPatches
{
	class ExpBookItem
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts",
			"DayZExpansion_Core_Scripts",
			"DayZExpansion_Book_Scripts"
		};
	};
};
class CfgMods
{
	class ExpBookItem
	{
		type="mod";
		dependencies[]=
		{
			"World",
			"Mission",
			"DZ_Expansion_Book"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"BookItemForExp/World"
				};
			};
			class missionScriptModule
			{
				files[]=
				{
					"BookItemForExp/Mission"
				};
			};
		};
	};
};
class cfgVehicles
{
	class Inventory_Base;
	class ExpBookItem: Inventory_Base
	{
		quantityShow = 0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\gear\books\Data\book.rvmat"}},{0.7,{"DZ\gear\books\Data\book.rvmat"}},{0.5,{"DZ\gear\books\Data\book_damage.rvmat"}},{0.3,{"DZ\gear\books\Data\book_damage.rvmat"}},{0.0,{"DZ\gear\books\Data\book_destruct.rvmat"}}};
				};
			};
		};
		
		scope=2;
		title="Field Manual";
		author = "U.S. Army";
		displayName="Field Manual";
		descriptionShort="Army Survival Field Manual. This is the official guide to surviving extreme and life-threatening situations.";
		model="\DZ\gear\books\book_kniga.p3d";
		rotationFlags=1;		
		itemSize[]={1,1};
		weight=1;

		hiddenSelections[]=
		{
			"camoGround"
		};
		hiddenSelectionsTextures[]=
		{
			"Z:\BookItemForExp\Data\BookItem.paa"
		};
	};
};

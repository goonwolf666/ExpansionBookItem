modded class MissionGameplay
{
	void OnBookTogglePressed()
	{
		if(!HasItemType("ExpBookItem"))	{// Early exit if player doesnt have the book
			return;
			}
	
		if (!GetExpansionSettings().GetBook(false).IsLoaded() || !GetExpansionSettings().GetBook().EnableBookMenu ){
			return;
			}

		ExpansionUIManager uiManager = GetDayZGame().GetExpansionGame().GetExpansionUIManager();	//! Reference to expansion ui manager
		ScriptView menu = uiManager.GetMenu();	//! Reference to current opened script view menu
		
		ExpansionBookMenu bookMenu = ExpansionBookMenu.Cast(menu);
		if (!bookMenu)
		{
			uiManager.CreateSVMenu("ExpansionBookMenu");
		}
		else if (bookMenu && bookMenu.IsVisible())
		{
			uiManager.CloseMenu();
		}
	}
	
	//bless you Zen
	bool HasItemType(string type)
	{
		PlayerBase m_Player; // Player to search
		array<EntityAI> items = {}; // Array for enumeration
	    
		m_Player = PlayerBase.Cast(GetGame().GetPlayer());	// Get current player
		if(!m_Player){  // Return false if can't get player
			return false;
			}
		m_Player.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, items); // Enumerate inventory
		
		for (int i = 0; i < items.Count(); i++) // Loop through items
		{
			// Check null and if type is what we're looking for, and if it's not ruined
			if (!items[i] || items[i].IsRuined() || items[i].GetType() != type)
				continue; // Continue iterating if not

			return true;
		}

		return false; // Return false if not found
	}
}
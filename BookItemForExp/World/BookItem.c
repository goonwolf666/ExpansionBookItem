class ExpBookItem extends ItemBase
{
	
	override bool DescriptionOverride(out string output)
	{
		//construct string for book description, depending on expansion book settings
		string cfgPath = "CfgVehicles ExpBookItem";
		GetGame().ConfigGetText(cfgPath + " descriptionShort", output);
		string additionalText;
		
		#ifdef EXPANSIONMODBOOK
			if (!GetExpansionSettings().GetBook(false).IsLoaded() || !GetExpansionSettings().GetBook().EnableBookMenu ){
				additionalText = " I'm not sure I can read this...";
			}
			else if (this.IsRuined()) {
				additionalText = " This copy is too damaged to read.";
			}
			else{
				string bookBinding = GetExpBookButtonText();
				{
					
					//additionalText = " Read by pressing [" + InputUtils.GetButtonNameFromInput("UAExpansionBookToggle", EInputDeviceType.MOUSE_AND_KEYBOARD) + "]";
					additionalText = " Read by pressing [" + bookBinding + "].";
				}
			}
		#else
			additionalText = " I'm not sure I can read this...";
		#endif
		
		output += additionalText;
		return true;
	}
	
	string GetExpBookButtonText()
	{
		string ret = "";
		map<int,ref TStringArray> button_map = InputUtils.GetComboButtonNamesFromInput("UAExpansionBookToggle", EInputDeviceType.MOUSE_AND_KEYBOARD);
		
		if (button_map && button_map.Count() > 0)
		{
			TStringArray buttons;
			for (int j = 0; j < button_map.Count(); j++)
			{
				if (j > 0)
				{
					ret += "; ";
				}
				
				buttons = button_map.GetElement(j);
				for (int i = 0; i < buttons.Count(); i++)
				{
					if (i > 0)
					{
						ret += " + ";
					}
					ret += buttons[i];
				}
			}
		}
		
		return ret;
	}
	
}

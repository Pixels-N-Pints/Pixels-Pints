class ReportCommand: ScrServerCommand
{
	protected ref PnP_API_Post_HttpElement m_PnP_API_HttpElement;
	protected ref PnP_API_Get_HttpElement m_PnP_API_GetHttpElement;
	//------------------------------------------------------------------------------------------------
	//! \return
	// Specify keyword of command
	//-----------------------------------------------------------------------------
	override string GetKeyword()
	{
		Print("Pixels and Pints - Chat command report loaded");
	
	/*	PnP_Network_Class apiNetwork = new PnP_Network_Class();
		apiNetwork.LoadFromFile("$profile:pixels_and_pints.json");
		Print(apiNetwork.apiURL);
		SCR_JsonSaveContext jsonData = new SCR_JsonSaveContext();
		string m_sPlayerName = "Hawke";
		string m_sMessage = "This is a test";

		
		if (!m_PnP_API_HttpElement)
			m_PnP_API_HttpElement = new PnP_API_Post_HttpElement();
		
		if (!m_PnP_API_GetHttpElement)
			m_PnP_API_GetHttpElement = new PnP_API_Get_HttpElement();
		
		jsonData.WriteValue("playerName",m_sPlayerName);
		jsonData.WriteValue("message",m_sMessage);
		
		m_PnP_API_GetHttpElement.ExecuteRequest(apiNetwork.apiURL, "status");
		m_PnP_API_HttpElement.ExecuteRequest(apiNetwork.apiURL, "playerreport", "", jsonData.ExportToString());
	*/
		return "report";
	}
	
	//------------------------------------------------------------------------------------------------
	//! \return
	// Run command server-side
	//-----------------------------------------------------------------------------
	override bool IsServerSide()
	{
		Print("Pixels and Pints - Chat command report IsServerSide");
		return true;
	}
	
	//------------------------------------------------------------------------------------------------
	//!
	//! \return
	// Set requirement to admin permission via RCON
	//-----------------------------------------------------------------------------
	override int RequiredRCONPermission()
	{
		Print("Pixels and Pints - Chat command report RCON Permission");
		return ERCONPermissions.PERMISSIONS_ADMIN;
	}
	
	//------------------------------------------------------------------------------------------------
	//!
	//! \return
	// Set requirement of player role
	//-----------------------------------------------------------------------------
	override int RequiredChatPermission()
	{
		Print("Pixels and Pints - Chat command report Chat Permission");
		return EPlayerRole.NONE;
	}
	
	//------------------------------------------------------------------------------------------------
	//!
	//! \param[in] argv
	//! \param[in] playerId
	//! \return
	// Shared handle for sending a report
	//-----------------------------------------------------------------------------
	protected ScrServerCmdResult HandleCommand(array<string> argv, int playerId = 0)
	{
		
		PnP_Network_Class apiNetwork = new PnP_Network_Class();
		apiNetwork.LoadFromFile("$profile:pixels_and_pints.json");
		Print(apiNetwork.apiURL);
	
		Print("Pixels and Pints - Chat command report SendReport");
		if (argv.Count() < 2)
			return ScrServerCmdResult(string.Empty, EServerCmdResultType.PARAMETERS);
		
		string m_sPlayerName = GetGame().GetPlayerManager().GetPlayerName(playerId);
		string m_sMessage = "";
		for (int i = 1, count = argv.Count(); i < count; i++)
		{
				m_sMessage += argv[i] + " ";
		}
		
		if (!m_PnP_API_HttpElement)
			m_PnP_API_HttpElement = new PnP_API_Post_HttpElement();
		
		SCR_JsonSaveContext jsonData = new SCR_JsonSaveContext();
		jsonData.WriteValue("playerName",m_sPlayerName);
		jsonData.WriteValue("message",m_sMessage);
		
		m_PnP_API_HttpElement.ExecuteRequest(apiNetwork.apiURL, "report", "", jsonData.ExportToString());

		Print(argv);
		return ScrServerCmdResult("report sent!", EServerCmdResultType.OK);
	}
	
	//------------------------------------------------------------------------------------------------
	//! \param[in] argv
	//! \param[in] playerId
	//! \return
	// Handle Chat command on server
	//-----------------------------------------------------------------------------
	override ref ScrServerCmdResult OnChatServerExecution(array<string> argv, int playerId)
	{
		Print("Pixels and Pints - Chat command report OnChatServerExecution");
		return HandleCommand(argv, playerId);
	}
	
	//------------------------------------------------------------------------------------------------
	//! \param[in] argv
	//! \param[in] playerId
	//! \return
	// Handle Chat command on client
	//-----------------------------------------------------------------------------
	override ref ScrServerCmdResult OnChatClientExecution(array<string> argv, int playerId)
	{
		Print("Pixels and Pints - Chat command report OnChatClientExecution");
		return ScrServerCmdResult(string.Empty, EServerCmdResultType.OK);
	}
	
	//------------------------------------------------------------------------------------------------
	//! \param[in] argv
	//! \return
	// Handle RCON command on server
	//-----------------------------------------------------------------------------
	override ref ScrServerCmdResult OnRCONExecution(array<string> argv)
	{
		Print("Pixels and Pints - Chat command report OnRCONExecution");
		return HandleCommand(argv);
	}
	
	//------------------------------------------------------------------------------------------------
	//! \return
	// Handle Pending command
	//-----------------------------------------------------------------------------
	override ref ScrServerCmdResult OnUpdate()
	{
		Print("Pixels and Pints - Chat command report OnUpdate");
		return ScrServerCmdResult(string.Empty, EServerCmdResultType.OK);
	}

}
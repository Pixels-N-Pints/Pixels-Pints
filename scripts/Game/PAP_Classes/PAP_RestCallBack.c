class PnP_RestCallBack : RestCallback
{
	//------------------------------------------------------------------------------------------------
	override void OnError(int errorCode)
	{
		Print("OnError()");
	}

	//------------------------------------------------------------------------------------------------
	override void OnTimeout()
	{
		Print("OnTimeout()");
	}

	//------------------------------------------------------------------------------------------------
	override void OnSuccess(string data, int dataSize)
	{
		Print("OnSuccess() - data size = " + dataSize + " bytes");
		if (dataSize > 0)
			Print(data); // note that Print() will not output strings longer than 1024b to console, check the dataSize!
	}
}
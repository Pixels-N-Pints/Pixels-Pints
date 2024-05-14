class PnP_Network_Class : JsonApiStruct
{
	string apiURL;

	void PnP_Network_Class()
	{
		RegV("apiURL");
	}
}


class PnP_API_Post_HttpElement
{
	protected ref PnP_RestCallBack m_PnP_RestCallBack;

	//------------------------------------------------------------------------------------------------
	void ExecuteRequest(string url, string endpoint, string request, string data)
	{
		if (!m_PnP_RestCallBack)
			m_PnP_RestCallBack = new PnP_RestCallBack();

		string contextURL = url;
		RestContext context = GetGame().GetRestApi().GetContext(contextURL);

		context.POST(m_PnP_RestCallBack,endpoint,"content="+data);
	}
}

class PnP_API_Get_HttpElement
{
	protected ref PnP_RestCallBack m_PnP_RestCallBack;

	//------------------------------------------------------------------------------------------------
	void ExecuteRequest(string url, string endpoint)
	{
		if (!m_PnP_RestCallBack)
			m_PnP_RestCallBack = new PnP_RestCallBack();

		string contextURL = url;
		RestContext context = GetGame().GetRestApi().GetContext(contextURL);

		context.GET(m_PnP_RestCallBack, endpoint);
	}
}
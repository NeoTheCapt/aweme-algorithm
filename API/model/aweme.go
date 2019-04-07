package model

type Json_masas struct {
	Mas string `json:"mas"`
	As  string `json:"as"`
	Ts  string `json:"ts"`
}

type Json_iid struct {
	MagicTag    string `json:"magic_tag"`
	Fingerprint string `json:"fingerprint"`
	Header      struct {
		SdkVersion    int    `json:"sdk_version"`
		Language      string `json:"language"`
		UserAgent     string `json:"user_agent"`
		AppVersion    string `json:"app_version"`
		VendorID      string `json:"vendor_id"`
		IsUpgradeUser bool   `json:"is_upgrade_user"`
		Region        string `json:"region"`
		Channel       string `json:"channel"`
		MccMnc        string `json:"mcc_mnc"`
		TzOffset      int    `json:"tz_offset"`
		AppRegion     string `json:"app_region"`
		Resolution    string `json:"resolution"`
		Aid           string `json:"aid"`
		Os            string `json:"os"`
		DeviceID      string `json:"device_id"`
		Custom        struct {
			AppRegion   string `json:"app_region"`
			AppLanguage string `json:"app_language"`
		} `json:"custom"`
		Access       string `json:"access"`
		Openudid     string `json:"openudid"`
		Carrier      string `json:"carrier"`
		InstallID    string `json:"install_id"`
		Timezone     int    `json:"timezone"`
		IsJailbroken bool   `json:"is_jailbroken"`
		DeviceModel  string `json:"device_model"`
		OsVersion    string `json:"os_version"`
		Mc           string `json:"mc"`
		DisplayName  string `json:"display_name"`
		Package      string `json:"package"`
		TzName       string `json:"tz_name"`
		AppLanguage  string `json:"app_language"`
		Idfa         string `json:"idfa"`
	} `json:"header"`
}
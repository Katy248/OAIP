OutputDll = ./bin/Release/net8.0/Weather.dll
build: $(OutputDll)

$(OutputDll):
	dotnet build --configuration Release 

run: $(OutputDll)
	dotnet $(OutputDll)
	
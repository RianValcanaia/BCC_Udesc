from types import SimpleNamespace

IF_ID = SimpleNamespace(RegisterRs=3, RegisterRt=2)
ID_EX = SimpleNamespace(RegisterRs=1, RegisterRt=3)
EX_MEM = SimpleNamespace(RegWrite=1, RegisterRd=5)  
MEM_WB = SimpleNamespace(RegWrite=1, RegisterRd=3)

ForwardA = "00"
ForwardB = "00"
stall = False

if ID_EX.MemRead and (
    (ID_EX.RegisterRt == IF_ID.RegisterRs) or
    (ID_EX.RegisterRt == IF_ID.RegisterRt)
):
    stall = True

if not stall:
    if EX_MEM.RegWrite and (EX_MEM.RegisterRd != 0) and (EX_MEM.RegisterRd == ID_EX.RegisterRs):
        ForwardA = "10"
    if EX_MEM.RegWrite and (EX_MEM.RegisterRd != 0) and (EX_MEM.RegisterRd == ID_EX.RegisterRt):
        ForwardB = "10"
    if MEM_WB.RegWrite and (MEM_WB.RegisterRd != 0) and (MEM_WB.RegisterRd == ID_EX.RegisterRs) and not (
        EX_MEM.RegWrite and (EX_MEM.RegisterRd != 0) and (EX_MEM.RegisterRd == ID_EX.RegisterRs)
    ):
        ForwardA = "01"
    if MEM_WB.RegWrite and (MEM_WB.RegisterRd != 0) and (MEM_WB.RegisterRd == ID_EX.RegisterRt) and not (
        EX_MEM.RegWrite and (EX_MEM.RegisterRd != 0) and (EX_MEM.RegisterRd == ID_EX.RegisterRt)
    ):
        ForwardB = "01"

# Exibir os resultados
print(f"ForwardA = {ForwardA}")
print(f"ForwardB = {ForwardB}")
print(f"Stall = {stall}")

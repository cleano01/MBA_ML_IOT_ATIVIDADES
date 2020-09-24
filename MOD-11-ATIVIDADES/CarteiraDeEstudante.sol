//SPDX-License-Identifier: MIT
pragma solidity ^0.6.8;

contract CarteiraDeEstudante {
    address dono_contrato; //contrato

    string numero_carteira;
    string nome_estudade;
    string data_nascimento;
    string instituicao;

    uint256 data_contrato;
    uint256 data_expericacao = 1654041600; //: Quarta-feira, 1 junho 2022 00:00:00

    bool contrato_ativo = true;

    constructor(
        string memory _nome,
        string memory _numero_carteira,
        string memory _data_nascimento,
        string memory _instituicao
    ) public {
        require(contrato_ativo == false, "Esse contrato nao esta mais ativado");

        dono_contrato = msg.sender;
        data_contrato = now;

        nome_estudade = _nome;
        numero_carteira = _numero_carteira;
        data_nascimento = _data_nascimento;
        instituicao = _instituicao;
    }

    function get()
        public
        view
        returns (
            address _dono,
            string memory _nome,
            string memory _numero_carteira,
            string memory _data_nascimento,
            string memory _instituicao,
            string memory _status_carteira,
            uint256 _data_expericacao
        )
    {
        return (
            dono_contrato,
            nome_estudade,
            numero_carteira,
            instituicao,
            data_nascimento,
            verifica_contrato(),
            data_expericacao
        );
    }

    function verifica_contrato() public view returns (string memory _status) {
        if (contrato_ativo) {
            return "Contrato ativo";
        } else {
            return "Contrato desativado";
        }
    }

    function desativar_contrato() public {
        require(msg.sender == dono_contrato, "Voce nao e dono do contrato");
        require(contrato_ativo == false, verifica_contrato());

        selfdestruct(msg.sender);
    }

    function verifica_data_carteira() public returns (bool _contrato_ativo) {
        require(contrato_ativo, verifica_contrato());

        if (now > data_expericacao + 1 days) {
            selfdestruct(msg.sender);
            contrato_ativo = false;
            return contrato_ativo;
        }
        return true;
    }

    function getDono() public view returns (address _dono_contrato) {
        return dono_contrato;
    }
}

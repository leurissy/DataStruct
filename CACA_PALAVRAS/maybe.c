        /*if(linha==0){//Linha 0
        	if(coluna==0){//L 0 e C 0
        		novo->leste = matriz[linha][coluna+1];
        		novo->sul = matriz[linha+1][coluna];
        		novo->sudeste = matriz[linha+1][coluna+1];
        		novo->oeste = NULL;
	            novo->norte = NULL;
	            novo->sudoeste = NULL;
	            novo->nordeste = NULL;
	            novo->noroeste = NULL;            			
        	}else{//Linha e Coluna !=0 
        		if(coluna==colunas-1){//Linha 0 e Coluna -1
        			novo->leste = NULL;
		    		novo->sul = matriz[linha+1][coluna];
		    		novo->sudeste = NULL;
		    		novo->oeste = matriz[linha][coluna-1];
		            novo->norte = NULL;
		            novo->sudoeste = matriz[linha+1][coluna-1];
		            novo->nordeste = NULL;
		            novo->noroeste = NULL;
        		}else{//Linha 0 e Coluna !=0 && -1
        			novo->leste = matriz[linha][coluna+1];
		    		novo->sul = matriz[linha+1][coluna];
		    		novo->sudeste = matriz[linha+1][coluna+1];
		    		novo->oeste = matriz[linha][coluna-1];
		            novo->norte = NULL;
		            novo->sudoeste = matriz[linha+1][coluna-1];
		            novo->nordeste = NULL;
		            novo->noroeste = NULL;
        		}
        	}
        }else{//Linha !=0
        	if(coluna==0){//Linha !=0 e Coluna 0
        		if(linha==linhas-1){//Linha -1 e Coluna 0
        			novo->leste = matriz[linha][coluna+1];
		    		novo->sul = NULL;
		    		novo->sudeste = NULL;
		    		novo->oeste = NULL;
		            novo->norte = matriz[linha-1][coluna];
		            novo->sudoeste = NULL;
		            novo->nordeste = matriz[linha-1][coluna+1];
		            novo->noroeste = NULL;
    			}else{//Linha !=0 && -1 e Coluna 0
    				novo->leste = matriz[linha][coluna+1];
            		novo->sul = matriz[linha+1][coluna];
            		novo->sudeste = matriz[linha+1][coluna+1];
            		novo->oeste = NULL;
		            novo->norte = matriz[linha-1][coluna];
		            novo->sudoeste = NULL;
		            novo->nordeste = matriz[linha-1][coluna+1];
		            novo->noroeste = NULL;
        		}            			
        	}else{//Linha !=0 e Coluna !=0
        		if(coluna==colunas-1){//Linha !=0 e Coluna -1
        			if(linha==linhas-1){//Linha !=0 && ==-1 e Coluna -1
            			novo->leste = NULL;
			    		novo->sul = matriz[linha+1][coluna];
			    		novo->sudeste = NULL;
			    		novo->oeste = matriz[linha][coluna-1];
			            novo->norte = NULL;
			            novo->sudoeste = matriz[linha+1][coluna-1];
			            novo->nordeste = NULL;
			            novo->noroeste = NULL;
        			}else{//Linha !=0 e Coluna -1
        				novo->leste = NULL;
			    		novo->sul = matriz[linha+1][coluna];
			    		novo->sudeste = NULL;
			    		novo->oeste = matriz[linha][coluna-1];
			            novo->norte = matriz[linha-1][coluna];
			            novo->sudoeste = matriz[linha+1][coluna-1];
			            novo->nordeste = NULL;
			            novo->noroeste = matriz[linha-1][coluna-1];
            		}
        		}else{//Linha !=0 e Coluna !=0 && -1
        			if(linha==linhas-1){//Linha !=0 && ==-1 e Coluna !=0 && -1
            			novo->leste = matriz[linha][coluna+1];
			    		novo->sul = NULL;
			    		novo->sudeste = NULL;
			    		novo->oeste = matriz[linha][coluna-1];
			            novo->norte = matriz[linha-1][coluna];
			            novo->sudoeste = NULL;
			            novo->nordeste = matriz[linha-1][coluna+1];
			            novo->noroeste = matriz[linha-1][coluna-1];
        			}else{//Linha !=0 && -1 e Coluna !=0 && -1
        				novo->leste = matriz[linha][coluna+1];
			    		novo->sul = matriz[linha+1][coluna];
			    		novo->sudeste = matriz[linha+1][coluna+1];
			    		novo->oeste = matriz[linha][coluna-1];
			            novo->norte = matriz[linha-1][coluna];
			            novo->sudoeste = matriz[linha+1][coluna-1];
			            novo->nordeste = matriz[linha-1][coluna+1];
			            novo->noroeste = matriz[linha-1][coluna-1];
        			}
        			
        		}
        	}
        }*/